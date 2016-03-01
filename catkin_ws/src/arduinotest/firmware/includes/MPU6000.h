#ifndef _MPU6000_H_
#define _MPU6000_H_

#include <ros.h>
#include "AP_Math.h"
#include <SPI.h>
#include <math.h>

class MPU6000 {

public:
  MPU6000(bool use_fifo, uint8_t chipSelect);

  /* update accel and gyro state */
  bool update();

  bool init(ros::NodeHandle& nh);

  /* Poll for new data */
  void read();

  void accel(float& x, float& y, float& z);
  void gyro(float& x, float& y, float& z);
  double temp();

private:
  /* Initialize sensor*/

  bool hardwareInit();
  bool calibrateGyroSensitivity();
  bool calibrateAccelerometerSensitivity();
  void start();

  void setFilterRegister(uint16_t filter_hz);
  void fifoReset();
  void fifoEnable();
  //  bool _has_auxiliary_bus();

  /* Read samples from FIFO (FIFO enabled) */
  void readFifo();

  /* Read a single sample (FIFO disabled) */
  void readSample();

  /* Check if there's data available by reading register */
  bool dataReady();



  /* Read and write functions taking the differences between buses into
  * account */
  void blockRead(uint8_t reg, uint8_t *buf, uint16_t size);
  uint8_t registerRead(uint8_t reg);
  void registerWrite(uint8_t reg, uint8_t val );

  void accumulate(uint8_t *samples, uint8_t n_samples);

  // instance numbers of accel and gyro data
  Vector3f _gyro;
  Vector3f _accel;
  float _temp;
  float _gyro_scaling[3] = {0,0,0};
  float _accel_scaling[3] = {0,0,0};

  const bool _use_fifo;
  const uint8_t _MPU6000ChipSelect;
  ros::NodeHandle _nh;

};

#endif // _MPU6000_H_
