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
    void enableThrusters(bool enable);
  private:
    void pwmSanityCheck(uint16_t* thruster_pwm_array);

    Servo _servo[6];
    bool _thrusters_enabled;
};

#endif //_ROV_SERVO_H_
