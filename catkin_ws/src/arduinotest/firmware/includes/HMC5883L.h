#ifndef _HMC5883L_H_
#define _HMC5883L_H_

#include "AP_Math.h"
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include "defines.h"


class HMC5883L {
public:
    HMC5883L();

    bool        init();
    void        read();
    void        magneticField(float& x, float& y, float& z);
    bool        calibrateOffsets();
private:

    float               _scaling[3] = {0};
    bool                readRaw();
    bool                reInitialise();
    bool                readRegister(uint8_t address, uint8_t& value);
    bool                readBlock(uint8_t address,
                                  uint8_t *value,
                                  uint32_t size);

    void                writeRegister(uint8_t address, uint8_t value);

    bool                calibrateSensitivity(uint8_t calibration_gain,
                                             uint16_t expected_x,
                                             uint16_t expected_yz);
    int16_t             readEEPROMInt16(uint16_t address);
    void                writeEEPROMInt16(uint16_t address, int16_t value);

    bool            _IO_fail;
    int16_t			    _mag_x;
    int16_t			    _mag_y;
    int16_t			    _mag_z;
    int16_t			    _mag_x_offset;
    int16_t			    _mag_y_offset;
    int16_t			    _mag_z_offset;
    Vector3f        _field;
    uint16_t        _address;

    float               _gain_multiple;
};

#endif // _HMC5883L_H_
