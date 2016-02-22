
#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt16MultiArray.h>


#include <Arduino.h>
#include <Servo.h>

// ROVIO rov_io;

// Node handle
ros::NodeHandle nh;

// Publishers
std_msgs::UInt16MultiArray sensor_message;
ros::Publisher sensor_publisher("rovio/sensors", sensor_message);

// Subscribers
//ros::Subscriber _thruster_subscriber;

// Internal objects
ROVServo _rov_servo;
MS5837 _water_pressure_sensor;

// Internal variables
uint16_t _pwm_array[6];

// Functions
void sendSensors() {
  std_msgs::UInt16 message;

  message.data = _water_pressure_sensor.pressure();
  sensor_publisher.publish(sensor_message);
}

// setup is where you run the code once
void setup() {

}

void loop() {
  rov_io.spin();
  delay(1000);
}
