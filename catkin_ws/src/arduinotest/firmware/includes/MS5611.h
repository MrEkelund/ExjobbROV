#ifndef _MS5611_H_
#define _MS5611_H_

#include <SPI.h>

class MS5611
{
public:
  MS5611(int chipSelect);
  void update();
  void accumulate();
private:
  void calculate();
  void init();

  bool readProm(uint16_t prom[8]);

  uint16_t readPromWord(uint8_t word);
  uint32_t readAdc();

  void _timer();

  /* Asynchronous state: */
  volatile bool            _updated;
  volatile uint8_t         _d1_count;
  volatile uint8_t         _d2_count;
  volatile uint32_t        _s_D1, _s_D2;
  uint8_t                  _state;
  uint32_t                 _last_timer;
  bool                     _timesliced;

  bool _use_timer;

  // Internal calibration registers
  uint16_t                 _c1,_c2,_c3,_c4,_c5,_c6;
  float                    _D1, _D2;
  uint8_t _instance;
  const int _MS5611ChipSelect
};

#endif //_MS5611_H_
