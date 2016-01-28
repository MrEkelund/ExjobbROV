// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

/*   Check for automatic takeoff conditions being met using the following sequence:
 *   1) Check for adequate GPS lock - if not return false
 *   2) Check the gravity compensated longitudinal acceleration against the threshold and start the timer if true
 *   3) Wait until the timer has reached the specified value (increments of 0.1 sec) and then check the GPS speed against the threshold
 *   4) If the GPS speed is above the threshold and the attitude is within limits then return true and reset the timer
 *   5) If the GPS speed and attitude within limits has not been achieved after 2.5 seconds, return false and reset the timer
 *   6) If the time lapsed since the last timecheck is greater than 0.2 seconds, return false and reset the timer
 *   NOTE : This function relies on the TECS 50Hz processing for its acceleration measure.
 */
static bool auto_takeoff_check(void)
{
    // this is a more advanced check that relies on TECS
    uint32_t now = hal.scheduler->millis();
    static bool launchTimerStarted;
    static uint32_t last_tkoff_arm_time;
    static uint32_t last_check_ms;

    // Reset states if process has been interrupted
    if (last_check_ms && (now - last_check_ms) > 200) {
        gcs_send_text_fmt(PSTR("Timer Interrupted AUTO"));
	    launchTimerStarted = false;
	    last_tkoff_arm_time = 0;
        last_check_ms = now;
        return false;
    }

    last_check_ms = now;

    // Check for bad GPS
    if (gps.status() < AP_GPS::GPS_OK_FIX_3D) {
        // no auto takeoff without GPS lock
        return false;
    }

    // Check for launch acceleration or timer started. NOTE: relies on TECS 50Hz processing
    if (!launchTimerStarted &&
        g.takeoff_throttle_min_accel != 0.0 &&
        SpdHgt_Controller->get_VXdot() < g.takeoff_throttle_min_accel) {
        goto no_launch;
    }

    // we've reached the acceleration threshold, so start the timer
    if (!launchTimerStarted) {
        launchTimerStarted = true;
        last_tkoff_arm_time = now;
        gcs_send_text_fmt(PSTR("Armed AUTO, xaccel = %.1f m/s/s, waiting %.1f sec"), 
                          SpdHgt_Controller->get_VXdot(), 0.1f*float(min(g.takeoff_throttle_delay,25)));
    }

    // Only perform velocity check if not timed out
    if ((now - last_tkoff_arm_time) > 2500) {
        gcs_send_text_fmt(PSTR("Timeout AUTO"));
        goto no_launch;
    }

    // Check aircraft attitude for bad launch
    if (ahrs.pitch_sensor <= -3000 ||
        ahrs.pitch_sensor >= 4500 ||
        abs(ahrs.roll_sensor) > 3000) {
        gcs_send_text_fmt(PSTR("Bad Launch AUTO"));
        goto no_launch;
    }

    // Check ground speed and time delay
    if (((gps.ground_speed() > g.takeoff_throttle_min_speed || g.takeoff_throttle_min_speed == 0.0)) && 
        ((now - last_tkoff_arm_time) >= min(uint16_t(g.takeoff_throttle_delay)*100,2500))) {
        gcs_send_text_fmt(PSTR("Triggered AUTO, GPSspd = %.1f"), gps.ground_speed());
        launchTimerStarted = false;
        last_tkoff_arm_time = 0;
        return true;
    }

    // we're not launching yet, but the timer is still going
    return false;

no_launch:
    launchTimerStarted = false;
    last_tkoff_arm_time = 0;
    return false;
}

/*
  calculate desired bank angle during takeoff, setting nav_roll_cd
 */
static void takeoff_calc_roll(void)
{
    if (steer_state.hold_course_cd == -1) {
        // we don't yet have a heading to hold - just level
        // the wings until we get up enough speed to get a GPS heading
        nav_roll_cd = 0;
        return;
    }

    calc_nav_roll();

    // during takeoff use the level flight roll limit to
    // prevent large course corrections
    nav_roll_cd = constrain_int32(nav_roll_cd, -g.level_roll_limit*100UL, g.level_roll_limit*100UL);
}

        
/*
  calculate desired pitch angle during takeoff, setting nav_pitch_cd
 */
static void takeoff_calc_pitch(void)
{
    if (auto_state.highest_airspeed < g.takeoff_rotate_speed) {
        // we have not reached rotate speed, use a target pitch of 5
        // degrees. This should be enough to get the tail off the
        // ground, while making it unlikely that overshoot in the
        // pitch controller will cause a prop strike
        nav_pitch_cd = 500;
        return;
    }

    if (ahrs.airspeed_sensor_enabled()) {
        calc_nav_pitch();
        if (nav_pitch_cd < auto_state.takeoff_pitch_cd) {
            nav_pitch_cd = auto_state.takeoff_pitch_cd;
        }
    } else {
        nav_pitch_cd = ((gps.ground_speed()*100) / (float)g.airspeed_cruise_cm) * auto_state.takeoff_pitch_cd;
        nav_pitch_cd = constrain_int32(nav_pitch_cd, 500, auto_state.takeoff_pitch_cd);
    }
}

/*
  return a tail hold percentage during initial takeoff for a tail
  dragger

  This can be used either in auto-takeoff or in FBWA mode with
  FBWA_TDRAG_CHAN enabled
 */
static int8_t takeoff_tail_hold(void)
{
    bool in_takeoff = ((control_mode == AUTO && !auto_state.takeoff_complete) ||
                       (control_mode == FLY_BY_WIRE_A && auto_state.fbwa_tdrag_takeoff_mode));
    if (!in_takeoff) {
        // not in takeoff
        return 0;
    }
    if (g.takeoff_tdrag_elevator == 0) {
        // no takeoff elevator set
        goto return_zero;
    }
    if (auto_state.highest_airspeed >= g.takeoff_tdrag_speed1) {
        // we've passed speed1. We now raise the tail and aim for
        // level pitch. Return 0 meaning no fixed elevator setting
        goto return_zero;
    }
    if (ahrs.pitch_sensor > auto_state.initial_pitch_cd + 1000) {
        // the pitch has gone up by more then 10 degrees over the
        // initial pitch. This may mean the nose is coming up for an
        // early liftoff, perhaps due to a bad setting of
        // g.takeoff_tdrag_speed1. Go to level flight to prevent a
        // stall
        goto return_zero;
    }
    // we are holding the tail down
    return g.takeoff_tdrag_elevator;

return_zero:
    if (auto_state.fbwa_tdrag_takeoff_mode) {
        gcs_send_text_P(SEVERITY_LOW, PSTR("FBWA tdrag off"));
        auto_state.fbwa_tdrag_takeoff_mode = false;
    }
    return 0;
}

/*
  return throttle percentage for takeoff
 */
static uint8_t takeoff_throttle(void)
{
    if (g.takeoff_throttle_max != 0) {
        return g.takeoff_throttle_max;
    }
    return aparm.throttle_max;
}
