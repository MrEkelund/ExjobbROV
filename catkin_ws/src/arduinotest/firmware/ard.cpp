#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"
#include "MS5611.h"
#include "MPU6000.h"


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
MS5611 air_pressure_sensor;
MPU6000 imu(false, 0x80);



// Internal variables
uint16_t pwm_array[6];

/******************************************************************************
*       Functions                                                             *
*******************************************************************************/
void sendSensors() {
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
  sensor_message.data[1] = air_pressure_sensor.pressure();
  // sensor_message.data[2] = air_pressure_sensor.temperature();
  // double x,y,z,temp;
  // imu.gyro(x,y,z);
  // sensor_message.data[0] = x;
  // sensor_message.data[1] = y;
  // sensor_message.data[2] = z;
  // imu.accel(x,y,z);
  // sensor_message.data[3] = x;
  // sensor_message.data[4] = y;
  // sensor_message.data[5] = z;
  // temp = imu.temp();
  // sensor_message.data[6] = temp;
  // sensor_message.data[7] = air_pressure_sensor.pressure();
  sensor_publisher.publish(&sensor_message);
}

void spin() {
  nh.spinOnce();
  //water_pressure_sensor.readProm();
  //delay(10);
  water_pressure_sensor.read();
  air_pressure_sensor.read();
  imu.pollData();

  sendSensors();
}


void setup() {
  nh.loginfo("Setting up");
  pinMode(BLUE_LED_PIN, OUTPUT);
  //pinMode(YELLOW_LED_PIN, OUTPUT);
  //pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(BLUE_LED_PIN,LOW);
  //digitalWrite(YELLOW_LED_PIN,LOW);
  //digitalWrite(RED_LED_PIN,HIGH);

  sensor_message.data_length = 2;
  sensor_message.layout.dim[0].size = sensor_message.data_length;
  sensor_message.layout.dim[0].stride = 1*sensor_message.data_length;
  sensor_message.layout.dim[0].label = "Sensors";
  sensor_message.data = (float*)malloc(sizeof(float)*sensor_message.data_length);

  for(int i = 0; i < sensor_message.data_length; i++) {
    sensor_message.data[i] = 0;
  }

  nh.loginfo("Starting sensors");
  Wire.begin();
  water_pressure_sensor.init(nh);
  water_pressure_sensor.setFluidDensity(997);

  nh.initNode();
  nh.advertise(sensor_publisher);

  SPI.begin();

  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  delay(100);

  air_pressure_sensor.init(40, nh);

  imu.init(53, nh);
  imu.start();
  digitalWrite(BLUE_LED_PIN, HIGH);
  //digitalWrite(YELLOW_LED_PIN, LOW);
  //digitalWrite(RED_LED_PIN, LOW);

}

void loop() {
  spin();

  delay(2000);
}
