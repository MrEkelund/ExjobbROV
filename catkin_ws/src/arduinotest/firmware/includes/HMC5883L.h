#ifndef _HMC5883L_H_
#define _HMC5883L_H_

#include "AP_Math.h"
#include <ros.h>
#include <ros/time.h>
#include <Wire.h>


class HMC5883L {
public:
    HMC5883L();

    void        init(ros::NodeHandle& nh);
    void        read();
    void        accumulate();
private:

    float               _scaling[3] = {0};
    bool                _initialised;
    bool                readRaw();
    bool                reInitialise();
    bool                readRegister(uint8_t address, uint8_t& value);
    bool                readBlock(uint8_t address,
                                  uint8_t *value,
                                  uint32_t size);

    void                writeRegister(uint8_t address, uint8_t value);

    bool                calibrate(uint8_t calibration_gain,
                                   uint16_t expected_x,
                                   uint16_t expected_yz);

    uint32_t            _retry_time;

    int16_t			    _mag_x;
    int16_t			    _mag_y;
    int16_t			    _mag_z;
    int16_t             _mag_x_accum;
    int16_t             _mag_y_accum;
    int16_t             _mag_z_accum;
    uint8_t			    _accum_count;
    uint32_t            _last_accum_time;

    float               _gain_multiple;
    ros::NodeHandle     _nh;
};

#endif // _HMC5883L_H_
