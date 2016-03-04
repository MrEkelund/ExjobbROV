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
#define STATUS_REGISTER 0x09
  #define LOCK  0x02
  #define RDY   0x01

#define MAG_GAIN         MAG_GAIN1090
#define MAG_BASE_CONFIG (SAMPLE_AVERAGING_8 | DATA_OUTPUT_RATE_75HZ | NORMAL_OPERATION)

HMC5883L::HMC5883L():
_IO_fail(false),
_mag_x(0),
_mag_y(0),
_mag_z(0) {}

// readBlock - read a block
bool HMC5883L::readBlock(uint8_t address, uint8_t* value, uint32_t size) {

  Wire.beginTransmission(HMC5883L_I2C_ADDR);
  Wire.write(address);
  Wire.endTransmission();

  Wire.beginTransmission(HMC5883L_I2C_ADDR);
  Wire.requestFrom(HMC5883L_I2C_ADDR, size);

  if ( Wire.available() == size) {
    for (uint8_t i = 0; i < size; i++) {
      value[i] = Wire.read();
    }
      return true;
  }

  _IO_fail = true;
  return false;
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
    _IO_fail = true;
  }

  int16_t rx, ry, rz;
  rx = (((int16_t)rv[0]) << 8) | rv[1];
  rz = (((int16_t)rv[2]) << 8) | rv[3];
  ry = (((int16_t)rv[4]) << 8) | rv[5];

  if (rx == -4096 || ry == -4096 || rz == -4096) {
    // no valid data available
    return false;
  }

  _mag_x = rx;
  _mag_y = ry;
  _mag_z = rz;

  return true;
}

/*
*  re-initialise after a IO error
*/
bool HMC5883L::reInitialise() {
  _IO_fail = false;
  writeRegister(CONFIG_REG_A, MAG_BASE_CONFIG);
  writeRegister(CONFIG_REG_B, MAG_GAIN);
  writeRegister(MODE_REGISTER, CONTINUOUS_CONVERSION);

  uint8_t reg1, reg2, reg3;
  bool status;
  status = readBlock(CONFIG_REG_A, &reg1, 1);
  status = readBlock(CONFIG_REG_B, &reg2, 1);
  status = readBlock(MODE_REGISTER, &reg3, 1);

  if(reg1 != MAG_BASE_CONFIG | reg2 != MAG_GAIN | reg3 != CONTINUOUS_CONVERSION) {
    return false;
  }
  return true;
}

// Public Methods //////////////////////////////////////////////////////////////
bool HMC5883L::init() {

  uint16_t expected_xy = 0;
  uint16_t expected_z = 0;
  uint8_t calibration_gain = 0;
  uint8_t gain = 0;
  bool success = false;

  switch (MAG_GAIN) {
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

  do {
    gain++;
    switch (gain) {
      case 1:
      calibration_gain = MAG_GAIN1370;
      expected_xy = 1.16*1370;
      expected_z = 1.08*1370;
      break;
      case 2:
      calibration_gain = MAG_GAIN1090;
      expected_xy = 1.16*1090;
      expected_z = 1.08*1090;
      break;
      case 3:
      calibration_gain = MAG_GAIN820;
      expected_xy = 1.16*820;
      expected_z = 1.08*820;
      break;
      case 4:
      calibration_gain = MAG_GAIN660;
      expected_xy = 1.16*660;
      expected_z = 1.08*660;
      break;
      case 5:
      calibration_gain = MAG_GAIN440;
      expected_xy = 1.16*440;
      expected_z = 1.08*440;
      break;
      case 6:
      calibration_gain = MAG_GAIN390;
      expected_xy = 1.16*390;
      expected_z = 1.08*390;
      break;
      case 7:
      calibration_gain = MAG_GAIN330;
      expected_xy = 1.16*330;
      expected_z = 1.08*330;
      break;
      case 8:
      calibration_gain = MAG_GAIN230;
      expected_xy = 1.16*230;
      expected_z = 1.08*230;
      break;
    }
    success = calibrateSensitivity(calibration_gain, expected_xy, expected_z);
  }
  while(!success && gain < 8);

  // leave test mode
  if (!reInitialise()) {
    success = false;
    _IO_fail = true;
  }

  _mag_x_offset = readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_X);
  _mag_y_offset = readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Y);
  _mag_z_offset = readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Z);

  // perform an initial read
  read();

  return success;
}

int16_t HMC5883L::readEEPROMInt16(uint16_t address) {
  uint8_t high = 0;
  uint8_t low = 0;
  high = EEPROM.read(address); // high bits
  low = EEPROM.read(address+1);

  return (high << 8) | low;
}

void HMC5883L::writeEEPROMInt16(uint16_t address, int16_t value) {
  uint8_t high = highByte(value);
  uint8_t low = lowByte(value);

  EEPROM.write(address, high); // high bits
  EEPROM.write(address + 1, low); // low bits
}

bool HMC5883L::calibrateSensitivity(uint8_t calibration_gain,
  uint16_t expected_xy,
  uint16_t expected_z) {

    int numAttempts = 0, good_count = 0;
    bool success = false;
    uint8_t reg1, reg2;
    bool read_status;

    while (!success && numAttempts < 25 && good_count < 5) {
      numAttempts++;

      // force positiveBias (compass should return 715 for all channels)
      writeRegister(CONFIG_REG_A, POSITIVE_BIAS_CONFIG);
      read_status = readBlock(CONFIG_REG_A, &reg1, 1);

      if (reg1 != POSITIVE_BIAS_CONFIG) {
        continue;   // compass not responding on the bus
      }


      delay(50);

      // set gains
      writeRegister(CONFIG_REG_B, calibration_gain);
      read_status = readBlock(CONFIG_REG_B, &reg1, 1);
      writeRegister(MODE_REGISTER, CONTINUOUS_CONVERSION);
      read_status = readBlock(MODE_REGISTER, &reg2, 1);
      if (reg1 != calibration_gain || reg2 != CONTINUOUS_CONVERSION) {
        continue;
    }

      // read values from the compass
      delay(50);
      if (!readRaw()){
        continue;      // we didn't read valid values
    }

      delay(10);

      float cal[3];

      cal[0] = fabsf(expected_xy / (float)_mag_x);
      cal[1] = fabsf(expected_xy / (float)_mag_y);
      cal[2] = fabsf(expected_z / (float)_mag_z);

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

bool HMC5883L::calibrateOffsets(float* min_max_array, bool last_test) {
  // float x_max = -4000, y_max = -4000, z_max = -4000;
  // float x_min = 4000, y_min = 4000, z_min = 4000;
  float x_max = min_max_array[0], y_max = min_max_array[2], z_max = min_max_array[4];
  float x_min = min_max_array[1], y_min = min_max_array[3], z_min = min_max_array[5];

  uint8_t count = 0;
  while (count < 2) { // ignore first samples
    if (readRaw()){
      count++;
    }
    delay(10);
  }

  uint8_t num_of_samples;
  while (num_of_samples < 20) {
    if (!readRaw()) {
      delay(10);
      continue;
    }

    num_of_samples++;
    x_max = max(x_max,_mag_x);
    x_min = min(x_min,_mag_x);
    y_max = max(y_max,_mag_y);
    y_min = min(y_min,_mag_y);
    z_max = max(z_max,_mag_z);
    z_min = min(z_min,_mag_z);
    delay(10);
  }

  if (last_test) {
    if ( x_max <= -4000 || x_min >= 4000 || y_max <= -4000 || y_min >= 4000 ||
      z_max <= -4000 || z_min >= 4000) {
        return false;
      }

      _mag_x_offset = (x_max - x_min)/2;
      _mag_y_offset = (y_max - y_min)/2;
      _mag_z_offset = (z_max - z_min)/2;

      writeEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_X, _mag_x_offset);
      writeEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Y, _mag_y_offset);
      writeEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Z, _mag_z_offset);
    }

    min_max_array[0] = x_max;
    min_max_array[1] = x_min;
    min_max_array[2] = y_max;
    min_max_array[3] = y_min;
    min_max_array[4] = z_max;
    min_max_array[5] = z_min;

    return true;
  }

// Read Sensor data
void HMC5883L::read() {

  if (_IO_fail) {
    delay(10);
    if (!reInitialise()) {
      _IO_fail = true;
      return;
    }
  }

  if (readRaw()) {
    // get raw_field - sensor frame, uncorrected
    _field = Vector3f((_mag_x - _mag_x_offset)*_scaling[0]
    , (_mag_y - _mag_y_offset)*_scaling[1]
    , (_mag_z - _mag_y_offset)*_scaling[2]);
    _field *= _gain_multiple;

  }
}

// Read Sensor data
void HMC5883L::magneticField(float& x, float& y, float& z) {
  _field.rotate(ROTATION_ROLL_180_YAW_270);
  x = _field[0]/10; // Convert to micro testla
  y = _field[1]/10; // Convert to micro testla
  z = _field[2]/10; // Convert to micro testla
}

float HMC5883L::getScaling() {
  return _gain_multiple;
}
