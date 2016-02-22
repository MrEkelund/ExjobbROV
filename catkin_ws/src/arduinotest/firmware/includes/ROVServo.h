#ifndef _ROV_SERVO_H_
#define _ROV_SERVO_H_

#include "defines.h"

#include <Arduino.h>
#include <Servo.h>

class ROVServo
{
  public:
    ROVServo();;
    void initROVServo();
    void setThrusters(uint16_t* thruster_pwm_array);

  private:
    void pwmSanityCheck(uint16_t* thruster_pwm_array);

    Servo _servo[6];
};

#endif //_ROV_SERVO_H_
