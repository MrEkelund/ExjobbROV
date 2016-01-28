// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#if LOGGING_ENABLED == ENABLED

// Code to Write and Read packets from DataFlash log memory
// Code to interact with the user to dump or erase logs

// These are function definitions so the Menu can be constructed before the functions
// are defined below. Order matters to the compiler.
static int8_t	dump_log(uint8_t argc, 			const Menu::arg *argv);
static int8_t	erase_logs(uint8_t argc, 		const Menu::arg *argv);
static int8_t	select_logs(uint8_t argc, 		const Menu::arg *argv);

// Creates a constant array of structs representing menu options
// and stores them in Flash memory, not RAM.
// User enters the string in the console to call the functions on the right.
// See class Menu in AP_Coommon for implementation details
static const struct Menu::command log_menu_commands[] PROGMEM = {
	{"dump",	dump_log},
	{"erase",	erase_logs},
	{"enable",	select_logs},
	{"disable",	select_logs}
};

// A Macro to create the Menu
MENU2(log_menu, "Log", log_menu_commands, print_log_menu);

static bool
print_log_menu(void)
{
	cliSerial->printf_P(PSTR("logs enabled: "));

	if (0 == g.log_bitmask) {
		cliSerial->printf_P(PSTR("none"));
	}else{
		// Macro to make the following code a bit easier on the eye.
		// Pass it the capitalised name of the log option, as defined
		// in defines.h but without the LOG_ prefix.  It will check for
		// the bit being set and print the name of the log option to suit.
		#define PLOG(_s)	if (g.log_bitmask & MASK_LOG_ ## _s) cliSerial->printf_P(PSTR(" %S"), PSTR(#_s))
		PLOG(ATTITUDE_FAST);
		PLOG(ATTITUDE_MED);
		PLOG(GPS);
		PLOG(PM);
		PLOG(CTUN);
		PLOG(NTUN);
		PLOG(MODE);
		PLOG(IMU);
		PLOG(CMD);
		PLOG(CURRENT);
		PLOG(SONAR);
		PLOG(COMPASS);
		PLOG(CAMERA);
		PLOG(STEERING);
		#undef PLOG
	}

	cliSerial->println();

    DataFlash.ListAvailableLogs(cliSerial);
	return(true);
}

static int8_t
dump_log(uint8_t argc, const Menu::arg *argv)
{
    int16_t dump_log;
    uint16_t dump_log_start;
    uint16_t dump_log_end;
    uint16_t last_log_num;

    // check that the requested log number can be read
    dump_log = argv[1].i;
    last_log_num = DataFlash.find_last_log();

    if (dump_log == -2) {
        DataFlash.DumpPageInfo(cliSerial);
        return(-1);
    } else if (dump_log <= 0) {
        cliSerial->printf_P(PSTR("dumping all\n"));
        Log_Read(0, 1, 0);
        return(-1);
    } else if ((argc != 2)
               || ((uint16_t)dump_log > last_log_num))
    {
        cliSerial->printf_P(PSTR("bad log number\n"));
        return(-1);
    }

    DataFlash.get_log_boundaries(dump_log, dump_log_start, dump_log_end);
    Log_Read((uint16_t)dump_log, dump_log_start, dump_log_end);
    return 0;
}


static void do_erase_logs(void)
{
	cliSerial->printf_P(PSTR("\nErasing log...\n"));
    DataFlash.EraseAll();
	cliSerial->printf_P(PSTR("\nLog erased.\n"));
}

static int8_t
erase_logs(uint8_t argc, const Menu::arg *argv)
{
    in_mavlink_delay = true;
    do_erase_logs();
    in_mavlink_delay = false;
    return 0;
}

static int8_t
select_logs(uint8_t argc, const Menu::arg *argv)
{
	uint16_t	bits;

	if (argc != 2) {
		cliSerial->printf_P(PSTR("missing log type\n"));
		return(-1);
	}

	bits = 0;

	// Macro to make the following code a bit easier on the eye.
	// Pass it the capitalised name of the log option, as defined
	// in defines.h but without the LOG_ prefix.  It will check for
	// that name as the argument to the command, and set the bit in
	// bits accordingly.
	//
	if (!strcasecmp_P(argv[1].str, PSTR("all"))) {
		bits = ~0;
	} else {
		#define TARG(_s)	if (!strcasecmp_P(argv[1].str, PSTR(#_s))) bits |= MASK_LOG_ ## _s
		TARG(ATTITUDE_FAST);
		TARG(ATTITUDE_MED);
		TARG(GPS);
		TARG(PM);
		TARG(CTUN);
		TARG(NTUN);
		TARG(MODE);
		TARG(IMU);
		TARG(CMD);
		TARG(CURRENT);
		TARG(SONAR);
		TARG(COMPASS);
		TARG(CAMERA);
		TARG(STEERING);
		#undef TARG
	}

	if (!strcasecmp_P(argv[0].str, PSTR("enable"))) {
		g.log_bitmask.set_and_save(g.log_bitmask | bits);
	}else{
		g.log_bitmask.set_and_save(g.log_bitmask & ~bits);
	}
	return(0);
}

static int8_t
process_logs(uint8_t argc, const Menu::arg *argv)
{
	log_menu.run();
	return 0;
}

struct PACKED log_Performance {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    uint32_t loop_time;
    uint16_t main_loop_count;
    uint32_t g_dt_max;
    int16_t  gyro_drift_x;
    int16_t  gyro_drift_y;
    int16_t  gyro_drift_z;
    uint8_t  i2c_lockup_count;
    uint16_t ins_error_count;
};

// Write a performance monitoring packet. Total length : 19 bytes
static void Log_Write_Performance()
{
    struct log_Performance pkt = {
        LOG_PACKET_HEADER_INIT(LOG_PERFORMANCE_MSG),
        time_ms         : millis(),
        loop_time       : millis()- perf_mon_timer,
        main_loop_count : mainLoop_count,
        g_dt_max        : G_Dt_max,
        gyro_drift_x    : (int16_t)(ahrs.get_gyro_drift().x * 1000),
        gyro_drift_y    : (int16_t)(ahrs.get_gyro_drift().y * 1000),
        gyro_drift_z    : (int16_t)(ahrs.get_gyro_drift().z * 1000),
        i2c_lockup_count: hal.i2c->lockup_count(),
        ins_error_count  : ins.error_count()
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

// Write a mission command. Total length : 36 bytes
static void Log_Write_Cmd(const AP_Mission::Mission_Command &cmd)
{
    mavlink_mission_item_t mav_cmd = {};
    AP_Mission::mission_cmd_to_mavlink(cmd,mav_cmd);
    DataFlash.Log_Write_MavCmd(mission.num_commands(),mav_cmd);
}

struct PACKED log_Steering {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    float demanded_accel;
    float achieved_accel;
};

// Write a steering packet
static void Log_Write_Steering()
{
    struct log_Steering pkt = {
        LOG_PACKET_HEADER_INIT(LOG_STEERING_MSG),
        time_ms        : hal.scheduler->millis(),
        demanded_accel : lateral_acceleration,
        achieved_accel : gps.ground_speed() * ins.get_gyro().z,
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

struct PACKED log_Startup {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    uint8_t startup_type;
    uint16_t command_total;
};

static void Log_Write_Startup(uint8_t type)
{
    struct log_Startup pkt = {
        LOG_PACKET_HEADER_INIT(LOG_STARTUP_MSG),
        time_ms         : millis(),
        startup_type    : type,
        command_total   : mission.num_commands()
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));

    // write all commands to the dataflash as well
    AP_Mission::Mission_Command cmd;
    for (uint16_t i = 0; i < mission.num_commands(); i++) {
        if(mission.read_cmd_from_storage(i,cmd)) {
            Log_Write_Cmd(cmd);
        }
    }
}

struct PACKED log_Control_Tuning {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    int16_t steer_out;
    int16_t roll;
    int16_t pitch;
    int16_t throttle_out;
    float accel_y;
};

// Write a control tuning packet. Total length : 22 bytes
static void Log_Write_Control_Tuning()
{
    Vector3f accel = ins.get_accel();
    struct log_Control_Tuning pkt = {
        LOG_PACKET_HEADER_INIT(LOG_CTUN_MSG),
        time_ms         : millis(),
        steer_out       : (int16_t)channel_steer->servo_out,
        roll            : (int16_t)ahrs.roll_sensor,
        pitch           : (int16_t)ahrs.pitch_sensor,
        throttle_out    : (int16_t)channel_throttle->servo_out,
        accel_y         : accel.y
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

struct PACKED log_Nav_Tuning {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    uint16_t yaw;
    float    wp_distance;
    uint16_t target_bearing_cd;
    uint16_t nav_bearing_cd;
    int8_t   throttle;
};

// Write a navigation tuning packet. Total length : 18 bytes
static void Log_Write_Nav_Tuning()
{
    struct log_Nav_Tuning pkt = {
        LOG_PACKET_HEADER_INIT(LOG_NTUN_MSG),
        time_ms             : millis(),
        yaw                 : (uint16_t)ahrs.yaw_sensor,
        wp_distance         : wp_distance,
        target_bearing_cd   : (uint16_t)nav_controller->target_bearing_cd(),
        nav_bearing_cd      : (uint16_t)nav_controller->nav_bearing_cd(),
        throttle            : (int8_t)(100 * channel_throttle->norm_output())
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

// Write an attitude packet
static void Log_Write_Attitude()
{
    Vector3f targets(0,0,0);       // Rover does not have attitude targets, use place-holder for commonality with Dataflash Log_Write_Attitude message

    DataFlash.Log_Write_Attitude(ahrs, targets);

#if AP_AHRS_NAVEKF_AVAILABLE
 #if defined(OPTFLOW) and (OPTFLOW == ENABLED)
    DataFlash.Log_Write_EKF(ahrs,optflow.enabled());
 #else
    DataFlash.Log_Write_EKF(ahrs,false);
 #endif
    DataFlash.Log_Write_AHRS2(ahrs);
#endif
}

struct PACKED log_Sonar {
    LOG_PACKET_HEADER;
    uint32_t time_ms;
    float    lateral_accel;
    uint16_t sonar1_distance;
    uint16_t sonar2_distance;
    uint16_t detected_count;
    int8_t   turn_angle;
    uint16_t turn_time;
    uint16_t ground_speed;
    int8_t   throttle;
};

// Write a sonar packet
static void Log_Write_Sonar()
{
    uint16_t turn_time = 0;
    if (obstacle.turn_angle != 0) {
        turn_time = hal.scheduler->millis() - obstacle.detected_time_ms;
    }
    struct log_Sonar pkt = {
        LOG_PACKET_HEADER_INIT(LOG_SONAR_MSG),
        time_ms         : millis(),
        lateral_accel   : lateral_acceleration,
        sonar1_distance : (uint16_t)sonar.distance_cm(0),
        sonar2_distance : (uint16_t)sonar.distance_cm(1),
        detected_count  : obstacle.detected_count,
        turn_angle      : (int8_t)obstacle.turn_angle,
        turn_time       : turn_time,
        ground_speed    : (uint16_t)(ground_speed*100),
        throttle        : (int8_t)(100 * channel_throttle->norm_output())
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

static void Log_Write_Current()
{
    DataFlash.Log_Write_Current(battery, channel_throttle->control_in);

    // also write power status
    DataFlash.Log_Write_Power();
}

static void Log_Write_RC(void)
{
    DataFlash.Log_Write_RCIN();
    DataFlash.Log_Write_RCOUT();
}

static void Log_Write_Baro(void)
{
    DataFlash.Log_Write_Baro(barometer);
}

static const struct LogStructure log_structure[] PROGMEM = {
    LOG_COMMON_STRUCTURES,
    { LOG_PERFORMANCE_MSG, sizeof(log_Performance), 
      "PM",  "IIHIhhhBH", "TimeMS,LTime,MLC,gDt,GDx,GDy,GDz,I2CErr,INSErr" },
    { LOG_STARTUP_MSG, sizeof(log_Startup),         
      "STRT", "IBH",        "TimeMS,SType,CTot" },
    { LOG_CTUN_MSG, sizeof(log_Control_Tuning),     
      "CTUN", "Ihcchf",     "TimeMS,Steer,Roll,Pitch,ThrOut,AccY" },
    { LOG_NTUN_MSG, sizeof(log_Nav_Tuning),         
      "NTUN", "IHfHHb",     "TimeMS,Yaw,WpDist,TargBrg,NavBrg,Thr" },
    { LOG_SONAR_MSG, sizeof(log_Sonar),             
      "SONR", "IfHHHbHCb",  "TimeMS,LatAcc,S1Dist,S2Dist,DCnt,TAng,TTim,Spd,Thr" },
    { LOG_STEERING_MSG, sizeof(log_Steering),             
      "STER", "Iff",   "TimeMS,Demanded,Achieved" },
};


// Read the DataFlash log memory : Packet Parser
static void Log_Read(uint16_t log_num, uint16_t start_page, uint16_t end_page)
{
    cliSerial->printf_P(PSTR("\n" FIRMWARE_STRING
                             "\nFree RAM: %u\n"),
                        (unsigned)hal.util->available_memory());

    cliSerial->println_P(PSTR(HAL_BOARD_NAME));

	DataFlash.LogReadProcess(log_num, start_page, end_page, 
                             print_mode,
                             cliSerial);
}

// start a new log
static void start_logging() 
{
    in_mavlink_delay = true;
    DataFlash.StartNewLog();
    in_mavlink_delay = false;
    DataFlash.Log_Write_Message_P(PSTR(FIRMWARE_STRING));

#if defined(PX4_GIT_VERSION) && defined(NUTTX_GIT_VERSION)
    DataFlash.Log_Write_Message_P(PSTR("PX4: " PX4_GIT_VERSION " NuttX: " NUTTX_GIT_VERSION));
#endif

    // write system identifier as well if available
    char sysid[40];
    if (hal.util->get_system_id(sysid)) {
        DataFlash.Log_Write_Message(sysid);
    }
}

#else // LOGGING_ENABLED

// dummy functions
static void Log_Write_Startup(uint8_t type) {}
static void Log_Write_Current() {}
static void Log_Write_Nav_Tuning() {}
static void Log_Write_Performance() {}
static void Log_Write_Cmd(const AP_Mission::Mission_Command &cmd) {}
static int8_t process_logs(uint8_t argc, const Menu::arg *argv) { return 0; }
static void Log_Write_Control_Tuning() {}
static void Log_Write_Sonar() {}
static void Log_Write_Attitude() {}
static void start_logging() {}
static void Log_Write_RC(void) {}

#endif // LOGGING_ENABLED

