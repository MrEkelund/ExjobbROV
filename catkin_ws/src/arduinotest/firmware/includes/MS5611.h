#ifndef _MS5611_H_
#define _MS5611_H_

#include <ros.h>
#include <SPI.h>

class MS5611
{
public:
  MS5611(uint8_t chipSelect);
  bool init();
  void read();
  float pressure();
  float temperature();
private:
  void calculate();
  void reset();

  bool readProm(uint16_t prom[8]);
  uint16_t readPromWord(uint8_t word);

  uint32_t readADC(uint8_t cmd);

  uint8_t         _d1_count;

  // Internal calibration registers
  uint16_t                 _c1,_c2,_c3,_c4,_c5,_c6;
  uint32_t                 _D1, _D2;
  float                    _temperature, _pressure;

  const uint8_t _MS5611ChipSelect;
};

#endif //_MS5611_H_
