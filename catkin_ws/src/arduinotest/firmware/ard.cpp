#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"
#include "MS5611.h"
#include "MPU6000.h"
#include "HMC5883L.h"


//#define USE_USBCON
#include <ros.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <SPI.h>


// Node handle
ros::NodeHandle nh;

// Publishers
std_msgs::Float32MultiArray sensor_message;
ros::Publisher sensor_publisher("rovio/sensors", &sensor_message);

// Subscribers
//ros::Subscriber _thruster_subscriber;

// Internal objects
ROVServo rov_servo;
MS5837 water_pressure_sensor;
MS5611 air_pressure_sensor(40);
MPU6000 imu(false, 53);
HMC5883L magnetometer;



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
  BLUE_LED_ON;
  water_pressure_sensor.read();
  air_pressure_sensor.read();
  imu.pollData();

  sendSensors();
  BLUE_LED_OFF;
}


void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  YELLOW_LED_OFF;
  BLUE_LED_OFF;
  RED_LED_ON;

  sensor_message.data_length = 2;
  sensor_message.layout.dim[0].size = sensor_message.data_length;
  sensor_message.layout.dim[0].stride = 1*sensor_message.data_length;
  sensor_message.layout.dim[0].label = "Sensors";
  sensor_message.data = (float*)malloc(sizeof(float)*sensor_message.data_length);

  nh.initNode();
  nh.advertise(sensor_publisher);

  Wire.begin();
  if (!water_pressure_sensor.init()) {
    nh.logerror("MS5837: Initialise fail");
  }
  magnetometer.init(nh);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  delay(100);

  if (!air_pressure_sensor.init()) {
    nh.logerror("MS5611: Initialise fail");
  }

  if (!imu.init()) {
    nh.logerror("MPU6000: Initialise fail");
  }
  imu.start();

  RED_LED_OFF;
}

void loop() {
  spin();

  delay(2000);
}
