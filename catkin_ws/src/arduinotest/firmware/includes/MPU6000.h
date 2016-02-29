#ifndef _MPU6000_H_
#define _MPU6000_H_

#include <ros.h>
#include "AP_Math.h"
#include <SPI.h>
//#include "AuxiliaryBus.h"

// enable debug to see a register dump on startup

//class AP_MPU6000_AuxiliaryBus;
//class AP_MPU6000_AuxiliaryBusSlave;

class MPU6000 {
  //friend AP_MPU6000_AuxiliaryBus;
  //friend AP_MPU6000_AuxiliaryBusSlave;

public:
  MPU6000(bool use_fifo, uint8_t chipSelect);

  /* update accel and gyro state */
  bool update();

  /*
  * Return an AuxiliaryBus if the bus driver allows it
  */
  //  AuxiliaryBus *get_auxiliary_bus() override;

  void start();

  bool init();

  /* Poll for new data */
  void pollData();

  void accel(float& x, float& y, float& z);
  void gyro(float& x, float& y, float& z);
  double temp();

private:
  /* Initialize sensor*/

  bool hardwareInit();

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

  const bool _use_fifo;
  const uint8_t _MPU6000ChipSelect;
  
  //AP_MPU6000_AuxiliaryBus *_auxiliary_bus;
};

/*
class AP_MPU6000_AuxiliaryBusSlave : public AuxiliaryBusSlave
{
friend class AP_MPU6000_AuxiliaryBus;

public:
int passthrough_read(uint8_t reg, uint8_t *buf, uint8_t size) override;
int passthrough_write(uint8_t reg, uint8_t val) override;

int read(uint8_t *buf) override;
_MPU6000_H_
protected:
AP_MPU6000_AuxiliaryBusSlave(AuxiliaryBus &bus, uint8_t addr, uint8_t instance);
int _set_passthrough(uint8_t reg, uint8_t size, uint8_t *out = nullptr);

private:
const uint8_t _mpu6000_addr;
const uint8_t _mpu6000_reg;
const uint8_t _mpu6000_ctrl;
const uint8_t _mpu6000_do;

uint8_t _ext_sens_data = 0;
};

class AP_MPU6000_AuxiliaryBus : public AuxiliaryBus
{
friend class AP_InertialSensor_MPU6000;

public:
AP_HAL::Semaphore *get_semaphore() override;

protected:
AP_MPU6000_AuxiliaryBus(AP_InertialSensor_MPU6000 &backend);

AuxiliaryBusSlave *_instantiate_slave(uint8_t addr, uint8_t instance) override;
int _configure_periodic_read(AuxiliaryBusSlave *slave, uint8_t reg,
uint8_t size) override;

private:
void _configure_slaves();

static const uint8_t MAX_EXT_SENS_DATA = 24;
uint8_t _ext_sens_data = 0;
};*/
#endif // _MPU6000_H_
