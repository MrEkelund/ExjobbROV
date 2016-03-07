#ifndef _MPU6000_H_
#define _MPU6000_H_

#include <ros.h>
#include "AP_Math.h"
#include <SPI.h>
#include <math.h>
#include <EEPROM.h>
#include "defines.h"

class MPU6000 {

public:
  MPU6000(uint8_t chipSelect);

  bool init();

  /* Poll for new data */
  bool read();

  void accel(float& x, float& y, float& z);
  void gyro(float& x, float& y, float& z);
  float temp();
  void calibrateGyroOffsets();
  bool calibrateAccelerometerOffsets(uint8_t test);
  float getAccelerometerScaling();
  float getGyroScaling();

private:
  /* Initialize sensor*/

  bool hardwareInit();
  bool calibrateGyroSensitivity();
  bool calibrateAccelerometerSensitivity();
  bool calibrateAccelerometerOffsetsSanity(uint8_t test);

  void start();

  void setFilterRegister(uint16_t filter_hz);

  /* Check if there's data available by reading register */
  bool dataReady();



  /* Read and write functions taking the differences between buses into
  * account */
  void blockRead(uint8_t reg, uint8_t *buf, uint16_t size);
  uint8_t registerRead(uint8_t reg);
  void registerWrite(uint8_t reg, uint8_t val );

  void calculate(uint8_t* data);

  void writeEEPROMInt16(uint16_t address, int16_t value);
  int16_t readEEPROMInt16(uint16_t address);
  // instance numbers of accel and gyro data
  Vector3f _gyro;
  Vector3f _accel;
  float _temp;
  float _gyro_scaling[3] = {0,0,0};
  float _accel_scaling[3] = {0,0,0};

  int16_t _gyro_offset[3] = {0,0,0};
  int16_t _accel_offset[3] = {0,0,0};
  int16_t _accel_offset_measurement[6] = {0,0,0,0,0,0};

  const uint8_t _MPU6000ChipSelect;

};

#endif // _MPU6000_H_
