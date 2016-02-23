#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"

//#define USE_USBCON
#include <ros.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>


#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <SPI.h>

// ROVIO rov_io;

// Node handle
ros::NodeHandle nh;

// Publishers
std_msgs::Float64MultiArray sensor_message;
ros::Publisher sensor_publisher("rovio/sensors", &sensor_message);

// Subscribers
//ros::Subscriber _thruster_subscriber;

// Internal objects
ROVServo rov_servo;
MS5837 water_pressure_sensor;

// Internal variables
uint16_t pwm_array[6];

/******************************************************************************
*       Functions                                                             *
*******************************************************************************/
void sendSensors() {
  water_pressure_sensor.read();
  //Serial.print("Pressure: /t");
  //Serial.println(water_pressure_sensor.pressure, DEC);
  // char temp[10];

  // dtostrf(water_pressure_sensor.pressure(),1,2,temp);
  //
  // nh.loginfo("Pressure");
  // nh.loginfo(temp);
  // dtostrf(water_pressure_sensor.altitude(),1,2,temp);
  // nh.loginfo("altitude");
  // nh.loginfo(temp);
  // dtostrf(water_pressure_sensor.temperature(),1,2,temp);
  // nh.loginfo("Temp");
  // nh.loginfo(temp);

  //water_pressure_sensor.readTestCase();
  sensor_message.data[0] = water_pressure_sensor.pressure();
  sensor_message.data[1] = water_pressure_sensor.altitude();
  sensor_publisher.publish(&sensor_message);
}

void spin() {
  nh.spinOnce();
  water_pressure_sensor.read();

  sendSensors();
}


void setup() {
  nh.loginfo("Setting up");

  sensor_message.data_length = 2;
  sensor_message.layout.dim[0].size = sensor_message.data_length;
  sensor_message.layout.dim[0].stride = 1*sensor_message.data_length;
  sensor_message.layout.dim[0].label = "Sensors";
  sensor_message.data = (float*)malloc(sizeof(float)*sensor_message.data_length);

  for(int i = 0; i < sensor_message.data_length; i++) {
    sensor_message.data[i] = 0;
  }

  Wire.begin();
  SPI.begin();
  water_pressure_sensor.init();
  water_pressure_sensor.setFluidDensity(997);

  nh.initNode();
  nh.advertise(sensor_publisher);
}

void loop() {
  spin();

  delay(1000);
}
