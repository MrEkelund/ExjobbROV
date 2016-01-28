// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
 *  geo-fencing support
 *  Andrew Tridgell, December 2011
 */

#if GEOFENCE_ENABLED == ENABLED

#define MIN_GEOFENCE_POINTS 5 // 3 to define a minimal polygon (triangle)
                              // + 1 for return point and +1 for last
                              // pt (same as first)

/*
 *  The state of geo-fencing. This structure is dynamically allocated
 *  the first time it is used. This means we only pay for the pointer
 *  and not the structure on systems where geo-fencing is not being
 *  used.
 *
 *  We store a copy of the boundary in memory as we need to access it
 *  very quickly at runtime
 */
static struct GeofenceState {
    uint8_t num_points;
    bool boundary_uptodate;
    bool fence_triggered;
    bool is_pwm_enabled;          //true if above FENCE_ENABLE_PWM threshold
    bool previous_is_pwm_enabled; //true if above FENCE_ENALBE_PWM threshold
                                  // last time we checked
    bool is_enabled;
    GeofenceEnableReason enable_reason;
    uint16_t breach_count;
    uint8_t breach_type;
    uint32_t breach_time;
    uint8_t old_switch_position;
    int32_t guided_lat;
    int32_t guided_lng;
    /* point 0 is the return point */
    Vector2l *boundary;
} *geofence_state;


static const StorageAccess fence_storage(StorageManager::StorageFence);

/*
  maximum number of fencepoints
 */
static uint8_t max_fencepoints(void)
{
    return min(255, fence_storage.size() / sizeof(Vector2l));
}

/*
 *  fence boundaries fetch/store
 */
static Vector2l get_fence_point_with_index(unsigned i)
{
    Vector2l ret;

    if (i > (unsigned)g.fence_total || i >= max_fencepoints()) {
        return Vector2l(0,0);
    }

    // read fence point
    ret.x = fence_storage.read_uint32(i * sizeof(Vector2l));
    ret.y = fence_storage.read_uint32(i * sizeof(Vector2l) + 4);

    return ret;
}

// save a fence point
static void set_fence_point_with_index(Vector2l &point, unsigned i)
{
    if (i >= (unsigned)g.fence_total.get() || i >= max_fencepoints()) {
        // not allowed
        return;
    }

    fence_storage.write_uint32(i * sizeof(Vector2l), point.x);
    fence_storage.write_uint32(i * sizeof(Vector2l)+4, point.y);

    if (geofence_state != NULL) {
        geofence_state->boundary_uptodate = false;
    }
}

/*
 *  allocate and fill the geofence state structure
 */
static void geofence_load(void)
{
    uint8_t i;

    if (geofence_state == NULL) {
        if (hal.util->available_memory() < 512 + sizeof(struct GeofenceState)) {
            // too risky to enable as we could run out of stack
            goto failed;
        }
        geofence_state = (struct GeofenceState *)calloc(1, sizeof(struct GeofenceState));
        if (geofence_state == NULL) {
            // not much we can do here except disable it
            goto failed;
        }

        geofence_state->boundary = (Vector2l *)calloc(sizeof(Vector2l), max_fencepoints());
        if (geofence_state->boundary == NULL) {
            free(geofence_state);
            geofence_state = NULL;
            goto failed;
        }
        
        geofence_state->old_switch_position = 254;
    }

    if (g.fence_total <= 0) {
        g.fence_total.set(0);
        return;
    }

    for (i=0; i<g.fence_total; i++) {
        geofence_state->boundary[i] = get_fence_point_with_index(i);
    }
    geofence_state->num_points = i;

    if (!Polygon_complete(&geofence_state->boundary[1], geofence_state->num_points-1)) {
        // first point and last point must be the same
        goto failed;
    }
    if (Polygon_outside(geofence_state->boundary[0], &geofence_state->boundary[1], geofence_state->num_points-1)) {
        // return point needs to be inside the fence
        goto failed;
    }

    geofence_state->boundary_uptodate = true;
    geofence_state->fence_triggered = false;

    gcs_send_text_P(SEVERITY_LOW,PSTR("geo-fence loaded"));
    gcs_send_message(MSG_FENCE_STATUS);
    return;

failed:
    g.fence_action.set(FENCE_ACTION_NONE);
    gcs_send_text_P(SEVERITY_HIGH,PSTR("geo-fence setup error"));
}

/*
 * return true if a geo-fence has been uploaded and
 * FENCE_ACTION is 1 (not necessarily enabled)
 */
static bool geofence_present(void)
{
    //require at least a return point and a triangle
    //to define a geofence area:
    if (g.fence_action == FENCE_ACTION_NONE || g.fence_total < MIN_GEOFENCE_POINTS) {
        return false;
    }
    return true;
}

/*
  check FENCE_CHANNEL and update the is_pwm_enabled state
 */
static void geofence_update_pwm_enabled_state() 
{
    bool is_pwm_enabled;
    if (g.fence_channel == 0) {
        is_pwm_enabled = false;
    } else {
        is_pwm_enabled = (hal.rcin->read(g.fence_channel-1) > FENCE_ENABLE_PWM);
    }
    if (is_pwm_enabled && geofence_state == NULL) {
        // we need to load the fence
        geofence_load();
        return;
    }

    if (geofence_state == NULL) {
        // not loaded
        return;
    }

    geofence_state->previous_is_pwm_enabled = geofence_state->is_pwm_enabled;
    geofence_state->is_pwm_enabled = is_pwm_enabled;

    if (geofence_state->is_pwm_enabled != geofence_state->previous_is_pwm_enabled) {
        geofence_set_enabled(geofence_state->is_pwm_enabled, PWM_TOGGLED);
    }    
}

//return true on success, false on failure
static bool geofence_set_enabled(bool enable, GeofenceEnableReason r) 
{
    if (geofence_state == NULL && enable) {
        geofence_load();
    }
    if (geofence_state == NULL) {
        return false;
    }

    geofence_state->is_enabled = enable;
    geofence_state->enable_reason = r;
    
    return true;
}

/*
 *  return true if geo-fencing is enabled
 */
static bool geofence_enabled(void)
{
    geofence_update_pwm_enabled_state();

    if (geofence_state == NULL) {
        return false;
    }

    if (g.fence_action == FENCE_ACTION_NONE ||
        !geofence_present() ||
        (g.fence_action != FENCE_ACTION_REPORT && !geofence_state->is_enabled)) {
        // geo-fencing is disabled
        // re-arm for when the channel trigger is switched on
        geofence_state->fence_triggered = false;
        return false;
    }

    return true;
}


/*
 *  return true if we have breached the geo-fence minimum altiude
 */
static bool geofence_check_minalt(void)
{
    if (g.fence_maxalt <= g.fence_minalt) {
        return false;
    }
    if (g.fence_minalt == 0) {
        return false;
    }
    return (adjusted_altitude_cm() < (g.fence_minalt*100.0) + home.alt);
}

/*
 *  return true if we have breached the geo-fence maximum altiude
 */
static bool geofence_check_maxalt(void)
{
    if (g.fence_maxalt <= g.fence_minalt) {
        return false;
    }
    if (g.fence_maxalt == 0) {
        return false;
    }
    return (adjusted_altitude_cm() > (g.fence_maxalt*100.0) + home.alt);
}


/*
 *  check if we have breached the geo-fence
 */
static void geofence_check(bool altitude_check_only)
{
    if (!geofence_enabled()) {
        // switch back to the chosen control mode if still in
        // GUIDED to the return point
        if (geofence_state != NULL &&
            (g.fence_action == FENCE_ACTION_GUIDED || g.fence_action == FENCE_ACTION_GUIDED_THR_PASS) &&
            control_mode == GUIDED &&
            geofence_present() &&
            geofence_state->boundary_uptodate &&
            geofence_state->old_switch_position == oldSwitchPosition &&
            guided_WP_loc.lat == geofence_state->guided_lat &&
            guided_WP_loc.lng == geofence_state->guided_lng) {
            geofence_state->old_switch_position = 254;
            set_mode(get_previous_mode());
        }
        return;
    }

    /* allocate the geo-fence state if need be */
    if (geofence_state == NULL || !geofence_state->boundary_uptodate) {
        geofence_load();
        if (!geofence_enabled()) {
            // may have been disabled by load
            return;
        }
    }

    bool outside = false;
    uint8_t breach_type = FENCE_BREACH_NONE;
    struct Location loc;

    if (geofence_check_minalt()) {
        outside = true;
        breach_type = FENCE_BREACH_MINALT;
    } else if (geofence_check_maxalt()) {
        outside = true;
        breach_type = FENCE_BREACH_MAXALT;
    } else if (!altitude_check_only && ahrs.get_position(loc)) {
        Vector2l location;
        location.x = loc.lat;
        location.y = loc.lng;
        outside = Polygon_outside(location, &geofence_state->boundary[1], geofence_state->num_points-1);
        if (outside) {
            breach_type = FENCE_BREACH_BOUNDARY;
        }
    }

    if (!outside) {
        if (geofence_state->fence_triggered && !altitude_check_only) {
            // we have moved back inside the fence
            geofence_state->fence_triggered = false;
            gcs_send_text_P(SEVERITY_LOW,PSTR("geo-fence OK"));
 #if FENCE_TRIGGERED_PIN > 0
            hal.gpio->pinMode(FENCE_TRIGGERED_PIN, HAL_GPIO_OUTPUT);
            hal.gpio->write(FENCE_TRIGGERED_PIN, 0);
 #endif
            gcs_send_message(MSG_FENCE_STATUS);
        }
        // we're inside, all is good with the world
        return;
    }

    // we are outside the fence
    if (geofence_state->fence_triggered &&
        (control_mode == GUIDED || g.fence_action == FENCE_ACTION_REPORT)) {
        // we have already triggered, don't trigger again until the
        // user disables/re-enables using the fence channel switch
        return;
    }

    // we are outside, and have not previously triggered.
    geofence_state->fence_triggered = true;
    geofence_state->breach_count++;
    geofence_state->breach_time = millis();
    geofence_state->breach_type = breach_type;

 #if FENCE_TRIGGERED_PIN > 0
    hal.gpio->pinMode(FENCE_TRIGGERED_PIN, HAL_GPIO_OUTPUT);
    hal.gpio->write(FENCE_TRIGGERED_PIN, 1);
 #endif

    gcs_send_text_P(SEVERITY_LOW,PSTR("geo-fence triggered"));
    gcs_send_message(MSG_FENCE_STATUS);

    // see what action the user wants
    switch (g.fence_action) {
    case FENCE_ACTION_REPORT:
        break;

    case FENCE_ACTION_GUIDED:
    case FENCE_ACTION_GUIDED_THR_PASS:
        if (g.fence_ret_rally != 0) { //return to a rally point
            guided_WP_loc = rally.calc_best_rally_or_home_location(current_loc, get_RTL_altitude());

        } else { //return to fence return point, not a rally point
            if (g.fence_retalt > 0) {
                //fly to the return point using fence_retalt
                guided_WP_loc.alt = home.alt + 100.0*g.fence_retalt;
            } else if (g.fence_minalt >= g.fence_maxalt) {
                // invalid min/max, use RTL_altitude
                guided_WP_loc.alt = home.alt + g.RTL_altitude_cm;
            } else {
                // fly to the return point, with an altitude half way between
                // min and max
                guided_WP_loc.alt = home.alt + 100.0*(g.fence_minalt + g.fence_maxalt)/2;
            }
            guided_WP_loc.options = 0;
            guided_WP_loc.lat = geofence_state->boundary[0].x;
            guided_WP_loc.lng = geofence_state->boundary[0].y;
        }
        geofence_state->guided_lat = guided_WP_loc.lat;
        geofence_state->guided_lng = guided_WP_loc.lng;
        geofence_state->old_switch_position = oldSwitchPosition;

        setup_terrain_target_alt(guided_WP_loc);

        set_guided_WP();

        // make sure we don't auto trim the surfaces on this mode change
        int8_t saved_auto_trim = g.auto_trim;
        g.auto_trim.set(0);

        set_mode(GUIDED);
        g.auto_trim.set(saved_auto_trim);

        if (g.fence_action == FENCE_ACTION_GUIDED_THR_PASS) {
            guided_throttle_passthru = true;
        }
        break;
    }

}

/*
 *  return true if geofencing allows stick mixing. When we have
 *  triggered failsafe and are in GUIDED mode then stick mixing is
 *  disabled. Otherwise the aircraft may not be able to recover from
 *  a breach of the geo-fence
 */
static bool geofence_stickmixing(void) {
    if (geofence_enabled() &&
        geofence_state != NULL &&
        geofence_state->fence_triggered &&
        control_mode == GUIDED) {
        // don't mix in user input
        return false;
    }
    // normal mixing rules
    return true;
}

/*
 *
 */
static void geofence_send_status(mavlink_channel_t chan)
{
    if (geofence_enabled() && geofence_state != NULL) {
        mavlink_msg_fence_status_send(chan,
                                      (int8_t)geofence_state->fence_triggered,
                                      geofence_state->breach_count,
                                      geofence_state->breach_type,
                                      geofence_state->breach_time);
    }
}

/*
  return true if geofence has been breached
 */
static bool geofence_breached(void)
{
    return geofence_state ? geofence_state->fence_triggered : false;
}


#else // GEOFENCE_ENABLED

static void geofence_check(bool altitude_check_only) {
}
static bool geofence_stickmixing(void) {
    return true;
}
static bool geofence_enabled(void) {
    return false;
}

static bool geofence_present(void) {
    return false;
}

static bool geofence_set_enabled(bool enable, GeofenceEnableReason r) {
    return false;
}

bool geofence_breached(void) {
    return false;
}

#endif // GEOFENCE_ENABLED
