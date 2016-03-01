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
#include <std_msgs/Bool.h>

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <SPI.h>
#include <EEPROM.h>


// Node handle
ros::NodeHandle nh;

// Publishers
std_msgs::Float32MultiArray sensor_message;
ros::Publisher sensor_publisher("rovio/sensors", &sensor_message);

// Subscribers
 // Forward declaration
void enableThrustersCallback(const std_msgs::Bool& message);
void thrustersCallback(const std_msgs::UInt16MultiArray& message);
void calibrateMagnetometerOffsetsCallback(const std_msgs::Bool& message);
void calibrateGyroOffsetsCallback(const std_msgs::Bool& control_msg);
void calibrateAccelerometerOffsetsCallback(const std_msgs::Bool& message);

ros::Subscriber<std_msgs::Bool>
                enable_thrusters_subscriber("rovio/enable_thrusters",
                                            &enableThrustersCallback);
ros::Subscriber<std_msgs::UInt16MultiArray>
                thrusters_subscriber("rovio/thrusters",
                                    &thrustersCallback);
ros::Subscriber<std_msgs::Bool>
                calibrate_magnetometer_offsets_subscriber("rovio/magnetometer/calibrate_offsets",
                                              &calibrateMagnetometerOffsetsCallback);
ros::Subscriber<std_msgs::Bool>
                calibrate_gyro_offsets_subscriber("rovio/gyro/calibrate_offsets",
                                              &calibrateGyroOffsetsCallback);
ros::Subscriber<std_msgs::Bool>
                calibrate_accelerometer_offsets_subscriber("rovio/accelerometer/calibrate_offsets",
                                              &calibrateAccelerometerOffsetsCallback);


// Internal objects
ROVServo rov_servo;
MS5837 water_pressure_sensor;
MS5611 air_pressure_sensor(40);
MPU6000 imu(false, 53);
HMC5883L magnetometer;

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
  // int16_t val;
  // EEPROM.get(EEPROM_MAGNETOMETER_OFFSET_X,val);
  // dtostrf(val,1,2,temp);
  // nh.loginfo("NEW");
  // nh.loginfo(temp);
  // EEPROM.get(EEPROM_MAGNETOMETER_OFFSET_X,val);
  // dtostrf(val,1,2,temp);
  //
  // nh.loginfo(temp);
  // EEPROM.get(EEPROM_MAGNETOMETER_OFFSET_X,val);
  // dtostrf(val,1,2,temp);
  // nh.loginfo(temp);

  float x,y,z;
  magnetometer.magneticField(x,y,z);
  imu.accel(x,y,z);
  sensor_message.data[0] = x;
  sensor_message.data[1] = y;
  sensor_message.data[2] = z;
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
  imu.read();
  magnetometer.read();

  sendSensors();
  BLUE_LED_OFF;
}

int16_t readEEPROMInt16(uint16_t address) {
  uint8_t high = 0;
  uint8_t low = 0;
  high = EEPROM.read(address); // high bits
  low = EEPROM.read(address+1);

  return (high << 8) | low;
}

/******************************************************************************
*       Callbacks                                                             *
*******************************************************************************/
void enableThrustersCallback(const std_msgs::Bool& message) {
  if (message.data) {
    RED_LED_OFF;
  } else {
    RED_LED_ON;
  }
  rov_servo.enableThrusters(message.data);
}

void thrustersCallback(const std_msgs::UInt16MultiArray& message) {
  YELLOW_LED_ON;
  rov_servo.setThrusters(message.data);
  YELLOW_LED_OFF;
}

void calibrateMagnetometerOffsetsCallback(const std_msgs::Bool& message) {
  YELLOW_LED_ON;
  RED_LED_ON;
  BLUE_LED_ON;
  nh.loginfo("Move the magnetometer in circles while rotating it for 30s");
  delay(5000);
  magnetometer.calibrateOffsets();
  nh.loginfo("Magnetometer calibrated");
  YELLOW_LED_OFF;
  RED_LED_OFF;
  BLUE_LED_OFF;
}

void calibrateGyroOffsetsCallback(const std_msgs::Bool& message) {
  YELLOW_LED_ON;
  RED_LED_ON;
  BLUE_LED_ON;
  char log_msg[24];
  char str_temp[6];
  int16_t val;
  nh.loginfo("Hold gyro still");
  delay(5000);
  imu.calibrateGyroOffsets();
  nh.loginfo("Calculated offset in sensor frame");

  val = readEEPROMInt16(EEPROM_GYRO_OFFSET_X);
  dtostrf(val, 4, 2, str_temp);
  sprintf(log_msg,"x offset: %s", str_temp);
  nh.loginfo(log_msg);
  val = readEEPROMInt16(EEPROM_GYRO_OFFSET_Y);
  dtostrf(val, 4, 2, str_temp);
  sprintf(log_msg,"y offset: %s", str_temp);
  nh.loginfo(log_msg);
  val = readEEPROMInt16(EEPROM_GYRO_OFFSET_Z);
  dtostrf(val, 4, 2, str_temp);
  sprintf(log_msg,"z offset: %s", str_temp);
  nh.loginfo(log_msg);
  YELLOW_LED_OFF;
  RED_LED_OFF;
  BLUE_LED_OFF;
}

bool cp=false;
void calibrateAccelerometerOffsetsCallback(const std_msgs::Bool& message) {
  cp = true;
  // YELLOW_LED_ON;
  // RED_LED_ON;
  // BLUE_LED_ON;
  // char log_msg[24];
  // char str_temp[6];
  // int16_t val;
  //
  // for (uint8_t i = 0; i < 5; i++) {
  //   switch (i) {
  //     case 0: // Right side up
  //     nh.logwarn("Hold right side up");
  //     break;
  //     case 1: // Left side up
  //     nh.logwarn("Hold left side up");
  //     break;
  //     case 2: // Front side up
  //     nh.logwarn("Hold forward side up");
  //     break;
  //     case 3: // Down side up
  //     nh.logwarn("Hold backward side up");
  //     break;
  //     case 4: // Up side up
  //     nh.logwarn("Hold up side up");
  //     break;
  //     case 5: // Down side up
  //     nh.logwarn("Hold down side up");
  //     break;
  //   }
  //   delay(1500);
  //   bool status = imu.calibrateAccelerometerOffsets(i);
  //   if (status) {
  //   nh.loginfo("Good axis");
  //   } else {
  //   nh.loginfo("Bad axis");
  //   break;
  //   }
  // }
  // // nh.loginfo("Left side up");
  // // nh.loginfo("Right side up");
  // //delay(500);
  //
  // // nh.loginfo("Calculated offset in sensor frame");
  // //
  // // val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_X);
  // // dtostrf(val, 4, 2, str_temp);
  // // sprintf(log_msg,"x offset: %s", str_temp);
  // // nh.loginfo(log_msg);
  // // //val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Y);
  // // dtostrf(val, 4, 2, str_temp);
  // // sprintf(log_msg,"y offset: %s", str_temp);
  // // nh.loginfo(log_msg);
  // // //val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Z);
  // // dtostrf(val, 4, 2, str_temp);
  // // sprintf(log_msg,"z offset: %s", str_temp);
  // // nh.loginfo(log_msg);
  // YELLOW_LED_OFF;
  // RED_LED_OFF;
  // BLUE_LED_OFF;
}

void cpw() {
  cp = false;
  YELLOW_LED_ON;
  RED_LED_ON;
  BLUE_LED_ON;
  char log_msg[24];
  char str_temp[6];
  int16_t val;

  for (uint8_t i = 0; i < 6; i++) {
    switch (i) {
      case 0: // Right side up
      nh.logwarn("Hold right side up");
      break;
      case 1: // Left side up
      nh.logwarn("Hold left side up");
      break;
      case 2: // Front side up
      nh.logwarn("Hold forward side up");
      break;
      case 3: // Down side up
      nh.logwarn("Hold backward side up");
      break;
      case 4: // Up side up
      nh.logwarn("Hold up side up");
      break;
      case 5: // Down side up
      nh.logwarn("Hold down side up");
      break;
    }
    delay(1500);
    bool status = imu.calibrateAccelerometerOffsets(i);
    if (status) {
    nh.loginfo("Good axis");
    } else {
    nh.loginfo("Bad axis");
    break;
    }
  }
  // nh.loginfo("Left side up");
  // nh.loginfo("Right side up");
  //delay(500);

  // nh.loginfo("Calculated offset in sensor frame");
  //
  // val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_X);
  // dtostrf(val, 4, 2, str_temp);
  // sprintf(log_msg,"x offset: %s", str_temp);
  // nh.loginfo(log_msg);
  // //val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Y);
  // dtostrf(val, 4, 2, str_temp);
  // sprintf(log_msg,"y offset: %s", str_temp);
  // nh.loginfo(log_msg);
  // //val = readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Z);
  // dtostrf(val, 4, 2, str_temp);
  // sprintf(log_msg,"z offset: %s", str_temp);
  // nh.loginfo(log_msg);
  YELLOW_LED_OFF;
  RED_LED_OFF;
  BLUE_LED_OFF;
}
/******************************************************************************
*       Setup and loop                                                        *
*******************************************************************************/

void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  YELLOW_LED_OFF;
  BLUE_LED_OFF;
  RED_LED_ON;

  sensor_message.data_length = 3;
  sensor_message.layout.dim[0].size = sensor_message.data_length;
  sensor_message.layout.dim[0].stride = 1*sensor_message.data_length;
  sensor_message.layout.dim[0].label = "Sensors";
  sensor_message.data = (float*)malloc(sizeof(float)*sensor_message.data_length);

  nh.initNode();
  nh.advertise(sensor_publisher);
  nh.subscribe(enable_thrusters_subscriber);
  nh.subscribe(thrusters_subscriber);
  nh.subscribe(calibrate_magnetometer_offsets_subscriber);
  nh.subscribe(calibrate_gyro_offsets_subscriber);
  nh.subscribe(calibrate_accelerometer_offsets_subscriber);

  Wire.begin();
  if (!water_pressure_sensor.init()) {
    nh.logerror("MS5837: Initialise fail");
  }
  if (!magnetometer.init()) {
    nh.logerror("HMC5883L: Initialise fail");
  }


  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  delay(100);

  if (!air_pressure_sensor.init()) {
    nh.logerror("MS5611: Initialise fail");
  }

  if (!imu.init(nh)) {
    nh.logerror("MPU6000: Initialise fail");
  }

  RED_LED_OFF;
}

void loop() {
  spin();
  if(cp)
  cpw();

  delay(100);
}
