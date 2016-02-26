#include "HMC5883L.h"

#define HMC5883L_I2C_ADDR      0x1E
#define CONFIG_REG_A           0x00
// Reg A
  #define NORMAL_OPERATION       0x00
  #define POSITIVE_BIAS_CONFIG   0x01
  #define NEGATIVE_BIAS_CONFIG   0x02

  #define SAMPLE_AVERAGING_1      0x00
  #define SAMPLE_AVERAGING_2      0x20
  #define SAMPLE_AVERAGING_4      0x40
  #define SAMPLE_AVERAGING_8      0x60

  #define DATA_OUTPUT_RATE_0_75HZ 0x00
  #define DATA_OUTPUT_RATE_1_5HZ  0x04
  #define DATA_OUTPUT_RATE_3HZ    0x08
  #define DATA_OUTPUT_RATE_7_5HZ  0x0C
  #define DATA_OUTPUT_RATE_15HZ   0x10
  #define DATA_OUTPUT_RATE_30HZ   0x14
  #define DATA_OUTPUT_RATE_75HZ   0x18

#define CONFIG_REG_B   0x01
// ConfigRegB gains
  #define MAG_GAIN1370 0x00
  #define MAG_GAIN1090 0x20
  #define MAG_GAIN820  0x40
  #define MAG_GAIN660  0x60
  #define MAG_GAIN440  0x80
  #define MAG_GAIN390  0xA0
  #define MAG_GAIN330  0xC0
  #define MAG_GAIN230  0xE0


#define MODE_REGISTER           0x02
// Mode register
  #define HIGH_SPEED_I2C        0x80
  #define CONTINUOUS_CONVERSION 0x00
  #define SINGLE_CONVERSION     0x01
  #define IDLE_MODE             0x02

// Data output register
#define DATA_OUTPUT_XH 0x03
#define DATA_OUTPUT_XL 0x04
#define DATA_OUTPUT_ZH 0x05
#define DATA_OUTPUT_ZL 0x06
#define DATA_OUTPUT_YH 0x07
#define DATA_OUTPUT_YL 0x08

// Status register
#define LOCK  0x02
#define RDY   0x01

#define CALIBRATION_GAIN MAG_GAIN660
#define MAG_GAIN         MAG_GAIN1090
#define MAG_BASE_CONFIG (SAMPLE_AVERAGING_8 | DATA_OUTPUT_RATE_75HZ | NORMAL_OPERATION)

HMC5883L::HMC5883L():
_retry_time(0),
_mag_x(0),
_mag_y(0),
_mag_z(0),
_mag_x_accum(0),
_mag_y_accum(0),
_mag_z_accum(0),
_accum_count(0),
_last_accum_time(0) {}

// readRegister - read a register value
bool HMC5883L::readRegister(uint8_t address, uint8_t& value) {
  uint32_t count = 0;
  Wire.requestFrom(HMC5883L_I2C_ADDR,1);

  while(Wire.available()) {
    count++;
    value = Wire.read();
  }
  if (count < 2) {
    return true;
  } else { // We received more than we asked for
    _nh.logwarn("HMC5883L: Recived more bytes than asked for");
    _retry_time = _nh.now().toSec() + 1;
    return false;
  }
}

// readBlock - read a block
bool HMC5883L::readBlock(uint8_t address, uint8_t *value, uint32_t size) {
  uint32_t count = 0;

  Wire.requestFrom(HMC5883L_I2C_ADDR, size);

  Wire.beginTransmission(HMC5883L_I2C_ADDR);
  Wire.write(address);
  Wire.endTransmission();

  while(Wire.available()) {
    if ( count < size) {
      value[count] = Wire.read();
    }
    count++;
  }
  if (count == size) {
    return true;
  } else { // We received more than we asked for
    _retry_time = _nh.now().toSec() + 1;
    _nh.logwarn("HMC5883L: Recived more/less bytes than asked for");
    return false;
  }
}

// writeRegister - update a register value
void HMC5883L::writeRegister(uint8_t address, uint8_t value) {
  Wire.beginTransmission(HMC5883L_I2C_ADDR);
  Wire.write(address);
  Wire.write(value);
  Wire.endTransmission();
}

// Read Sensor data
bool HMC5883L::readRaw() {
  uint8_t rv[6]; // 2 register per axis

  if (!readBlock(DATA_OUTPUT_XH, rv, sizeof(rv))) {
    _retry_time = _nh.now().toSec() + 1;
  }

  int16_t rx, ry, rz;
  rx = (((int16_t)rv[0]) << 8) | rv[1];
  rz = (((int16_t)rv[2]) << 8) | rv[3];
  ry = (((int16_t)rv[4]) << 8) | rv[5];

  if (rx == -4096 || ry == -4096 || rz == -4096) {
    // no valid data available
    return false;
  }

  _mag_x = -rx;
  _mag_y =  ry;
  _mag_z = -rz;

  return true;
}


// accumulate a reading from the magnetometer
void HMC5883L::accumulate( ) {
  uint32_t tnow = _nh.now().toSec();
  if (_accum_count != 0 && (tnow - _last_accum_time) < 13333) {
    // the compass gets new data at 75Hz
    return;
  }

  if (readRaw()) {
    // the _mag_N values are in the range -2048 to 2047, so we can
    // accumulate up to 15 of them in an int16_t. Let's make it 14
    // for ease of calculation. We expect to do reads at 10Hz, and
    // we get new data at most 75Hz, so we don't expect to
    // accumulate more than 8 before a read
    // get raw_field - sensor frame, uncorrected
    Vector3f raw_field = Vector3f(_mag_x, _mag_y, _mag_z);
    raw_field *= _gain_multiple;

    // rotate raw_field from sensor frame to body frame
    //  rotate_field(raw_field, _compass_instance);
    //
    //  // publish raw_field (uncorrected point sample) for calibration use
    //  publish_raw_field(raw_field, tnow, _compass_instance);
    //
    //  // correct raw_field for known errors
    //  correct_field(raw_field, _compass_instance);
    //
    //  // publish raw_field (corrected point sample) for EKF use
    //  publish_unfiltered_field(raw_field, tnow, _compass_instance);

    _mag_x_accum += raw_field.x;
    _mag_y_accum += raw_field.y;
    _mag_z_accum += raw_field.z;
    _accum_count++;
    if (_accum_count == 14) {
      _mag_x_accum /= 2;
      _mag_y_accum /= 2;
      _mag_z_accum /= 2;
      _accum_count = 7;
    }
  }
}


/*
*  re-initialise after a IO error
*/
bool HMC5883L::reInitialise() {

  writeRegister(CONFIG_REG_A, MAG_BASE_CONFIG);
  writeRegister(CONFIG_REG_B, MAG_GAIN);
  writeRegister(MODE_REGISTER, CONTINUOUS_CONVERSION);

  uint8_t reg1, reg2, reg3;
  bool status;
  status = readRegister(CONFIG_REG_A, reg1);
  status = readRegister(CONFIG_REG_B, reg2);
  status = readRegister(MODE_REGISTER, reg3);

  if(reg1 != MAG_BASE_CONFIG | reg2 != MAG_GAIN | reg3 != CONTINUOUS_CONVERSION) {
    return false;
  }
  return true;
}

// Public Methods //////////////////////////////////////////////////////////////
void HMC5883L::init(ros::NodeHandle& nh) {

  _nh = nh;
  _nh.loginfo("HMC5883L: Initializing");
  uint16_t expected_x = 766;
  uint16_t expected_yz = 713;

  switch (CALIBRATION_GAIN) {
    case MAG_GAIN1370:
    _gain_multiple = (1.0f / 1370) * 1000;
    break;
    case MAG_GAIN1090:
    _gain_multiple = (1.0f / 1090) * 1000;
    break;
    case MAG_GAIN820:
    _gain_multiple = (1.0f / 820) * 1000;
    break;
    case MAG_GAIN660:
    _gain_multiple = (1.0f / 660) * 1000;
    break;
    case MAG_GAIN440:
    _gain_multiple = (1.0f / 440) * 1000;
    break;
    case MAG_GAIN390:
    _gain_multiple = (1.0f / 390) * 1000;
    break;
    case MAG_GAIN330:
    _gain_multiple = (1.0f / 330) * 1000;
    break;
    case MAG_GAIN230:
    _gain_multiple = (1.0f / 230) * 1000;
    break;
  }

  if (!calibrate(CALIBRATION_GAIN, expected_x, expected_yz)) {
    _nh.logwarn("HMC5883L: Couldn't configure sensor");
  }

  // leave test mode
  if (!reInitialise()) {
    _nh.logerror("HMC5883L: Couldn't reinitialise sensor");
  }

  // perform an initial read
  read();
}

bool HMC5883L::calibrate(uint8_t calibration_gain,
  uint16_t expected_x,
  uint16_t expected_yz) {

    int numAttempts = 0, good_count = 0;
    bool success = false;
    uint8_t reg1, reg2;
    bool read_status;

    while (success == 0 && numAttempts < 25 && good_count < 5)
    {
      numAttempts++;

      // force positiveBias (compass should return 715 for all channels)
      writeRegister(CONFIG_REG_A, POSITIVE_BIAS_CONFIG);
      read_status = readRegister(CONFIG_REG_A, reg1);
      if (reg1 != POSITIVE_BIAS_CONFIG)
      continue;   // compass not responding on the bus

      delay(50);

      // set gains
      writeRegister(CONFIG_REG_B, CALIBRATION_GAIN);
      read_status = readRegister(CONFIG_REG_B, reg1);
      writeRegister(CONFIG_REG_B, CALIBRATION_GAIN);
      read_status = readRegister(MODE_REGISTER, reg2);
      if (reg1 != CALIBRATION_GAIN || reg2 != SINGLE_CONVERSION)
      continue;

      // read values from the compass
      delay(50);
      if (!readRaw())
      continue;      // we didn't read valid values

      delay(10);

      float cal[3];

      cal[0] = fabsf(expected_x / (float)_mag_x);
      cal[1] = fabsf(expected_yz / (float)_mag_y);
      cal[2] = fabsf(expected_yz / (float)_mag_z);

      // we throw away the first two samples as the compass may
      // still be changing its state from the application of the
      // strap excitation. After that we accept values in a
      // reasonable range

      if (numAttempts <= 2) {
        continue;
      }

      #define IS_CALIBRATION_VALUE_VALID(val) (val > 0.7f && val < 1.35f)

      if (IS_CALIBRATION_VALUE_VALID(cal[0]) &&
      IS_CALIBRATION_VALUE_VALID(cal[1]) &&
      IS_CALIBRATION_VALUE_VALID(cal[2])) {
        // hal.console->printf("car=%.2f %.2f %.2f good\n", cal[0], cal[1], cal[2]);
        good_count++;

        _scaling[0] += cal[0];
        _scaling[1] += cal[1];
        _scaling[2] += cal[2];
      }

      #undef IS_CALIBRATION_VALUE_VALID

    }

    if (good_count >= 5) {
      _scaling[0] = _scaling[0] / good_count;
      _scaling[1] = _scaling[1] / good_count;
      _scaling[2] = _scaling[2] / good_count;
      success = true;
    } else {
      /* best guess */
      _scaling[0] = 1.0;
      _scaling[1] = 1.0;
      _scaling[2] = 1.0;
    }

    return success;
  }

// Read Sensor data
void HMC5883L::read() {

  if (_retry_time != 0) {
    if (_nh.now().toSec() < _retry_time) {
      return;
    }
    if (!reInitialise()) {
      _retry_time = _nh.now().toSec() + 1;
      return;
    }
  }

  if (_accum_count == 0) {
    accumulate();
    if (_retry_time != 0) {
      return;
    }
  }

  Vector3f field(_mag_x_accum * _scaling[0],
    _mag_y_accum * _scaling[1],
    _mag_z_accum * _scaling[2]);
    field /= _accum_count;

    _accum_count = 0;
    _mag_x_accum = _mag_y_accum = _mag_z_accum = 0;

    field.rotate(ROTATION_YAW_90);

    // publish_filtered_field(field, _compass_instance);
    _retry_time = 0;
  }

//
// /* MPU6000 implementation of the HMC5843 */
// AP_HMC5843_SerialBus_MPU6000::AP_HMC5843_SerialBus_MPU6000(AP_InertialSensor &ins,
//                                                            uint8_t addr)
// {
//     // Only initialize members. Fails are handled by configure or while
//     // getting the semaphore
//     _bus = ins.get_auxiliary_bus(HAL_INS_MPU60XX_SPI);
//     if (!_bus)
//         return;
//     _slave = _bus->request_next_slave(addr);
// }
//
// AP_HMC5843_SerialBus_MPU6000::~AP_HMC5843_SerialBus_MPU6000()
// {
//     /* After started it's owned by AuxiliaryBus */
//     if (!_started)
//         delete _slave;
// }
//
// bool AP_HMC5843_SerialBus_MPU6000::configure()
// {
//     if (!_bus || !_slave)
//         return false;
//     return true;
// }
//
// void AP_HMC5843_SerialBus_MPU6000::set_high_speed(bool val)
// {
// }
//
// uint8_t AP_HMC5843_SerialBus_MPU6000::register_read(uint8_t reg, uint8_t *buf, uint8_t size)
// {
//     return _slave->passthrough_read(reg, buf, size) == size ? 0 : 1;
// }
//
// uint8_t AP_HMC5843_SerialBus_MPU6000::register_write(uint8_t reg, uint8_t val)
// {
//     return _slave->passthrough_write(reg, val) >= 0 ? 0 : 1;
// }
//
// AP_HAL::Semaphore* AP_HMC5843_SerialBus_MPU6000::get_semaphore()
// {
//     return _bus ? _bus->get_semaphore() : nullptr;
// }
//
// uint8_t AP_HMC5843_SerialBus_MPU6000::read_raw(struct raw_value *rv)
// {
//     if (_started)
//         return _slave->read((uint8_t*)rv) >= 0 ? 0 : 1;
//
//     return _slave->passthrough_read(0x03, (uint8_t*)rv, sizeof(*rv)) >= 0 ? 0 : 1;
// }
//
// bool AP_HMC5843_SerialBus_MPU6000::start_measurements()
// {
//     if (_bus->register_periodic_read(_slave, 0x03, sizeof(struct raw_value)) < 0)
//         return false;
//
//     _started = true;
//
//     return true;
// }
