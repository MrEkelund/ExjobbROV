#include "MS5611.h"

static const uint8_t CMD_MS5611_RESET = 0x1E;
static const uint8_t CMD_MS5611_READ_ADC = 0x00;

/* PROM start address */
static const uint8_t CMD_MS5611_PROM = 0xA0;

// /* write to one of these addresses to start pressure conversion */
// #define ADDR_CMD_CONVERT_D1_OSR256  0x40
// #define ADDR_CMD_CONVERT_D1_OSR512  0x42
// #define ADDR_CMD_CONVERT_D1_OSR1024 0x44
// #define ADDR_CMD_CONVERT_D1_OSR2048 0x46
// #define ADDR_CMD_CONVERT_D1_OSR4096 0x48
//
// /* write to one of these addresses to start temperature conversion */
// #define ADDR_CMD_CONVERT_D2_OSR256  0x50
// #define ADDR_CMD_CONVERT_D2_OSR512  0x52
// #define ADDR_CMD_CONVERT_D2_OSR1024 0x54
// #define ADDR_CMD_CONVERT_D2_OSR2048 0x56
// #define ADDR_CMD_CONVERT_D2_OSR4096 0x58

#define CMD_RESET 0x1E // ADC reset command
#define CMD_ADC_READ 0x00 // ADC read command
#define CMD_ADC_CONV 0x40 // ADC conversion command
#define CMD_ADC_D1 0x00 // ADC D1 conversion
#define CMD_ADC_D2 0x10 // ADC D2 conversion
#define CMD_ADC_256 0x00 // ADC OSR=256
#define CMD_ADC_512 0x02 // ADC OSR=512
#define CMD_ADC_1024 0x04 // ADC OSR=1024
#define CMD_ADC_2048 0x06 // ADC OSR=2056
#define CMD_ADC_4096 0x08 // ADC OSR=4096


/*
use an OSR of 1024 to reduce the self-heating effect of the
sensor. Information from MS tells us that some individual sensors
are quite sensitive to this effect and that reducing the OSR can
make a big difference
*/
static const uint8_t CMD_PRESSURE_OSR = CMD_ADC_1024;
static const uint8_t CMD_TEMPERATURE_OSR = CMD_ADC_1024;

/*
constructor
*/
MS5611::MS5611(uint8_t chipSelect): _MS5611ChipSelect(chipSelect) {
    pinMode(_MS5611ChipSelect, OUTPUT);
}

bool MS5611::init() {

  reset();

  uint16_t prom[8];
  uint8_t tries = 0;
  while (!readProm(prom) && tries < 10) {
    tries++;
    delay(100);
  }

  // Save factory calibration coefficients
  _c1 = prom[1];
  _c2 = prom[2];
  _c3 = prom[3];
  _c4 = prom[4];
  _c5 = prom[5];
  _c6 = prom[6];

  _D1 = readADC(CMD_ADC_D1+CMD_PRESSURE_OSR);
  _D2 = readADC(CMD_ADC_D2+CMD_TEMPERATURE_OSR);
  if (tries < 10) {
    return true;
  }
  return true;
}

void MS5611::reset() {
  // take the chip select low to select the device:
  digitalWrite(_MS5611ChipSelect, LOW);

  SPI.transfer(CMD_MS5611_RESET);  //Send command
  delay(4);

  // take the chip select high to de-select:
  digitalWrite(_MS5611ChipSelect, HIGH);
}

/**
* MS56XX crc4 method from datasheet for 16 bytes (8 short values)
*/
static uint16_t crc4(uint16_t *data) {
  uint16_t n_rem = 0;
  uint8_t n_bit;

  for (uint8_t cnt = 0; cnt < 16; cnt++) {
    /* uneven bytes */
    if (cnt & 1) {
      n_rem ^= (uint8_t)((data[cnt >> 1]) & 0x00FF);
    } else {
      n_rem ^= (uint8_t)(data[cnt >> 1] >> 8);
    }

    for (n_bit = 8; n_bit > 0; n_bit--) {
      if (n_rem & 0x8000) {
        n_rem = (n_rem << 1) ^ 0x3000;
      } else {
        n_rem = (n_rem << 1);
      }
    }
  }

  return (n_rem >> 12) & 0xF;
}


uint16_t MS5611::readPromWord(uint8_t word) {
  const uint8_t reg = CMD_MS5611_PROM + (word << 1);
  uint8_t high_reg;
  uint8_t low_reg;

  // take the chip select low to select the device:
  digitalWrite(_MS5611ChipSelect, LOW);
  SPI.transfer(reg);
  high_reg =SPI.transfer(CMD_MS5611_READ_ADC); // Read the MSB
  low_reg = SPI.transfer(CMD_MS5611_READ_ADC); // Read the LSB

  // take the chip select high to de-select:
  digitalWrite(_MS5611ChipSelect, HIGH);

  return (high_reg << 8) | low_reg;
}

uint32_t MS5611::readADC(uint8_t cmd) {
  uint32_t temp = 0;

  digitalWrite(_MS5611ChipSelect, LOW);
  SPI.transfer(CMD_ADC_CONV+cmd);
  switch (cmd & 0x0f) // wait necessary conversion time
  {
    case CMD_ADC_256 : delay(1); break;
    case CMD_ADC_512 : delay(3); break;
    case CMD_ADC_1024: delay(4); break;
    case CMD_ADC_2048: delay(6); break;
    case CMD_ADC_4096: delay(10); break;
    default : break;
  }
  digitalWrite(_MS5611ChipSelect, HIGH);
  digitalWrite(_MS5611ChipSelect, LOW);
  SPI.transfer(CMD_ADC_READ); // Send ADC read command
  temp = 65536*SPI.transfer(CMD_ADC_READ); // Read the MSB
  temp = temp + 256*SPI.transfer(CMD_ADC_READ);
  temp = temp + SPI.transfer(CMD_ADC_READ); // Read the LSB

  // take the chip select high to de-select:
  digitalWrite(_MS5611ChipSelect, HIGH);

  return temp;
}

bool MS5611::readProm(uint16_t prom[8]) {
  /*
  * MS5611-01BA datasheet, CYCLIC REDUNDANCY CHECK (CRC): "MS5611-01BA
  * contains a PROM memory with 128-Bit. A 4-bit CRC has been implemented
  * to check the data validity in memory."
  *
  * CRC field must me removed for CRC-4 calculation.
  */
  for (uint8_t i = 0; i < 8; i++) {
    prom[i] = readPromWord(i);
  }

  /* save the read crc */
  const uint16_t crc_read = prom[7] & 0xf;

  /* remove CRC byte */
  prom[7] &= 0xff00;

  return crc_read == crc4(prom);
}

/* Read the sensor. Read the pressure for times more often then
  the temperature */
void MS5611::read() {
  if(_d1_count < 4) {
    _d1_count++;
  } else {
    _d1_count = 0;
    _D1 = readADC(CMD_ADC_D1+CMD_ADC_512);
  }

  _D2 = readADC(CMD_ADC_D2+CMD_ADC_512);

  calculate();
}


// Calculate Temperature and compensated Pressure in real units (Celsius degrees*100, mbar*100).
void MS5611::calculate() {
  float dT;
  float TEMP;
  float OFF;
  float SENS;

  // Formulas from manufacturer datasheet
  // sub -15c temperature compensation is not included

  // we do the calculations using floating point allows us to take advantage
  // of the averaging of D1 and D1 over multiple samples, giving us more
  // precision
  dT = _D2-(((uint32_t)_c5)<<8);
  TEMP = (dT * _c6)/8388608;
  OFF = _c2 * 65536.0f + (_c4 * dT) / 128;
  SENS = _c1 * 32768.0f + (_c3 * dT) / 256;


  if (TEMP < 0) {
    // second order temperature compensation when under 20 degrees C
    float T2 = (dT*dT) / 0x80000000;
    float Aux = TEMP*TEMP;
    float OFF2 = 2.5f*Aux;
    float SENS2 = 1.25f*Aux;
    TEMP = TEMP - T2;
    OFF = OFF - OFF2;
    SENS = SENS - SENS2;
  }

  _pressure = (_D1*SENS/2097152 - OFF)/32768;
  _temperature = (TEMP + 2000) * 0.01f;
}

float MS5611::pressure() {
  return _pressure;
}

float MS5611::temperature() {
  return _temperature;
}
