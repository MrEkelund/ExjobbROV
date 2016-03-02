#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"
#include "MS5611.h"
#include "MPU6000.h"
#include "HMC5883L.h"


//#define USE_USBCON
#include <ros.h>
#include <ros/time.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>

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
void loopRateCallback(const std_msgs::Float32& message);

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
ros::Subscriber<std_msgs::Float32>
                sample_time_subscriber("sensor_fusion/sample_time",
                                              &loopRateCallback);

// Internal objects
ROVServo rov_servo;
MS5837 water_pressure_sensor;
MS5611 air_pressure_sensor(40);
MPU6000 imu(53);
HMC5883L magnetometer;

uint32_t last_call;
float pressure_offset;
float sample_time = 1;

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

  // float x,y,z;
  // imu.gyro(x,y,z);
  // sensor_message.OmegaX = x;
  // sensor_message.OmegaY = y;
  // sensor_message.OmegaZ = z;
  // imu.accel(x,y,z);
  // sensor_message.AccX = x;
  // sensor_message.AccY = y;
  // sensor_message.AccZ = z;
  // magnetometer.magneticField(x,y,z);
  // sensor_message.MagX = x;
  // sensor_message.MagY = y;
  // sensor_message.MagZ = z;
  // sensor_message.Pressure = water_pressure_sensor.pressure() - pressure_offset;

  float x,y,z;
  imu.gyro(x,y,z);
  sensor_message.data[0] = x;
  sensor_message.data[1] = y;
  sensor_message.data[2] = z;
  imu.accel(x,y,z);
  sensor_message.data[3] = x;
  sensor_message.data[4] = y;
  sensor_message.data[5] = z;
  magnetometer.magneticField(x,y,z);
  sensor_message.data[6] = x;
  sensor_message.data[7] = y;
  sensor_message.data[8] = z;
  sensor_message.data[9] = water_pressure_sensor.pressure() - pressure_offset;

  sensor_publisher.publish(&sensor_message);
}

void spin() {
  BLUE_LED_ON;
  water_pressure_sensor.read();
  //air_pressure_sensor.read();
  imu.read();
  magnetometer.read();
  sendSensors();
  BLUE_LED_OFF;

  nh.spinOnce();
}

int16_t readEEPROMInt16(uint16_t address) {
  uint8_t high = 0;
  uint8_t low = 0;
  high = EEPROM.read(address); // high bits
  low = EEPROM.read(address+1);

  return (high << 8) | low;
}

void rate() {
  uint32_t time_diff = millis() - last_call;
  float period = sample_time*1000;
  if ( time_diff < period) {
      delay(period - time_diff);
  }

  last_call = millis();
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
  uint16_t pwm_array[6];
  YELLOW_LED_ON;
  rov_servo.setThrusters(pwm_array);
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
  char str_temp[9];
  float val;
  nh.logwarn("Hold gyro still");
  delay(5000);
  imu.calibrateGyroOffsets();
  nh.loginfo("Calculated offset in sensor frame");

  float scale = imu.getGyroScaling();
  val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_X);
  dtostrf(val, 5, 4, str_temp);
  sprintf(log_msg,"x offset: %s", str_temp);
  nh.loginfo(log_msg);
  val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_Y);
  dtostrf(val, 5, 4, str_temp);
  sprintf(log_msg,"y offset: %s", str_temp);
  nh.loginfo(log_msg);
  val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_Z);
  dtostrf(val, 5, 4, str_temp);
  sprintf(log_msg,"z offset: %s", str_temp);
  nh.loginfo(log_msg);

  YELLOW_LED_OFF;
  RED_LED_OFF;
  BLUE_LED_OFF;
}

void calibrateAccelerometerOffsetsCallback(const std_msgs::Bool& message) {
  bool success = false;
  YELLOW_LED_ON;
  RED_LED_ON;
  BLUE_LED_ON;
  char log_msg[24];
  char str_temp[9];
  float val;

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
    delay(3000);
    bool status = imu.calibrateAccelerometerOffsets(i);
    if (status) {
      success = true;
    } else {
      nh.logerror("Not correct axis. calibration aborted");
      success = false;
      break;
    }
  }

  if (success) {
    nh.loginfo("Calculated offset in sensor frame");
    float scale = imu.getAccelerometerScaling();
    val = scale*readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_X);
    dtostrf(val, 5, 4, str_temp);
    sprintf(log_msg,"x offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Y);
    dtostrf(val, 5, 4, str_temp);
    sprintf(log_msg,"y offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Z);
    dtostrf(val, 5, 4, str_temp);
    sprintf(log_msg,"z offset: %s", str_temp);
    nh.loginfo(log_msg);
  }
  YELLOW_LED_OFF;
  RED_LED_OFF;
  BLUE_LED_OFF;
}

void loopRateCallback(const std_msgs::Float32& message) {
  sample_time = message.data;
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

  sensor_message.data_length = 10;
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
  nh.subscribe(sample_time_subscriber);

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

  if (!imu.init()) {
    nh.logerror("MPU6000: Initialise fail");
  }


  for (uint8_t i = 0; i < 10; i++) {
    air_pressure_sensor.read();
    delay(10);
    pressure_offset += air_pressure_sensor.pressure()/10;
  }

  if (pressure_offset < 81300 || pressure_offset > 121300) {
    nh.logwarn("Couldn't measure air pressure. Defaulting");
    pressure_offset = 101300;
  }

  last_call = millis();
  RED_LED_OFF;
}

void loop() {
  spin();

  rate();
}
