/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_BARO_PX4_H__
#define __AP_BARO_PX4_H__

#include "AP_Baro.h"

class AP_Baro_PX4 : public AP_Baro_Backend
{
public:
    AP_Baro_PX4(AP_Baro &);
    void update();

private:
    uint8_t _num_instances;

    struct px4_instance {
        uint8_t instance;
        int fd;
        float pressure_sum;
        float temperature_sum;
        uint32_t sum_count;
        uint64_t last_timestamp;
    } instances[BARO_MAX_INSTANCES];
};

#endif //  __AP_BARO_PX4_H__
