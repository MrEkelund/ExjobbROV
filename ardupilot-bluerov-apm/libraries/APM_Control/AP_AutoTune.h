// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_AUTOTUNE_H__
#define __AP_AUTOTUNE_H__

#include <AP_HAL.h>
#include <AP_Param.h>
#include <DataFlash.h>

class AP_AutoTune {
public:
    struct ATGains {
        AP_Float tau;
        AP_Float P;
        AP_Float I;
        AP_Float D;
        AP_Int16 rmax;
        AP_Int16 imax;
    };

    enum ATType {
        AUTOTUNE_ROLL  = 0,
        AUTOTUNE_PITCH = 1
    };

    struct PACKED log_ATRP {
        LOG_PACKET_HEADER;
        uint32_t timestamp;
        uint8_t  type;
        uint8_t  state;
        int16_t  servo;
        float    demanded;
        float    achieved;
        float    P;
    };


    // constructor
    AP_AutoTune(ATGains &_gains, ATType type, const AP_Vehicle::FixedWing &parms, DataFlash_Class &_dataflash);

    // called when autotune mode is entered
    void start(void);

    // called to stop autotune and restore gains when user leaves
    // autotune
    void stop(void);

    // update called whenever autotune mode is active. This is
    // typically at 50Hz
    void update(float desired_rate, float achieved_rate, float servo_out);

    // are we running?
    bool running:1;
    
private:
    // the current gains
    ATGains &current;

    // what type of autotune is this
    ATType type;

	const AP_Vehicle::FixedWing &aparm;

    DataFlash_Class &dataflash;

    // did we saturate surfaces?
    bool saturated_surfaces:1;

    // values to restore if we leave autotune mode
    ATGains restore; 

    // values we last saved
    ATGains last_save; 

    // values to save on the next save event
    ATGains next_save;

    // time when we last saved
    uint32_t last_save_ms;

    // the demanded/achieved state
    enum ATState {DEMAND_UNSATURATED,
                  DEMAND_UNDER_POS, 
                  DEMAND_OVER_POS,
                  DEMAND_UNDER_NEG,
                  DEMAND_OVER_NEG} state;

    // when we entered the current state
    uint32_t state_enter_ms;

    void check_save(void);
    void check_state_exit(uint32_t state_time_ms);
    void save_gains(const ATGains &v);

    void write_log_headers(void);
    void write_log(float servo, float demanded, float achieved);

    void log_param_change(float v, const prog_char_t *suffix);
    void save_float_if_changed(AP_Float &v, float value, const prog_char_t *suffix);
    void save_int16_if_changed(AP_Int16 &v, int16_t value, const prog_char_t *suffix);        
};

#endif // __AP_AUTOTUNE_H__

