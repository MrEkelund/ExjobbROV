#include "ROVServo.h"
// ROVServo constructor
ROVServo::ROVServo(): _thrusters_enabled(false), _emergency(false) {
}

// Initialize the ROV thrusters.
void ROVServo::init() {
  // Attach the servos to pins
  _servo[0].attach(SERVO1);
  _servo[1].attach(SERVO2);
  _servo[2].attach(SERVO3);
  _servo[3].attach(SERVO4);
  _servo[4].attach(SERVO5);
  _servo[5].attach(SERVO6);

  resetThrusters();
}

// Check if the pwm signals are higher/lower then allowed.
void ROVServo::pwmSanityCheck(uint16_t* thruster_pwm_array) {
  for (int i = 0; i < 6; i++) {
    if (thruster_pwm_array[i] < THRUSTERMIN) {
      thruster_pwm_array[i] = THRUSTERMIN;
    }
    else if (thruster_pwm_array[i] > THRUSTERMAX) {
      thruster_pwm_array[i] = THRUSTERMAX;
    }
  }
}

// Set the thrusters output in microseconds.
void ROVServo::setThrusters(uint16_t* thruster_pwm_array) {
  pwmSanityCheck(thruster_pwm_array);

  if (!_emergency) {
    if (_thrusters_enabled) {
      for (int i = 0; i < 6; i++) {
        _servo[i].writeMicroseconds(thruster_pwm_array[i]);
      }
    }
  }
}

// Enable or disable the thrusters
void ROVServo::enableThrusters(bool enabled) {
  _thrusters_enabled = enabled;
}

void ROVServo::resetThrusters() {
  for (int i = 0; i < 6; i++) {
    _servo[i].writeMicroseconds(THRUSTERSTOP);
  }
}

void ROVServo::setEmergency(bool emergency) {
  _emergency = emergency;
}
