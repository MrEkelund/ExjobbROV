#ifndef _HMC5883L_H_
#define _HMC5883L_H_

#include "AP_Math.h"
#include <ros.h>
#include <ros/time.h>
#include <Wire.h>


class HMC5883L {
public:
    HMC5883L();

    bool        init();
    void        read();
    void        magneticField(float& x, float& y, float& z);
private:

    float               _scaling[3] = {0};
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

    bool            _IO_fail;
    int16_t			    _mag_x;
    int16_t			    _mag_y;
    int16_t			    _mag_z;
    Vector3f        _field;

    float               _gain_multiple;
};

#endif // _HMC5883L_H_
