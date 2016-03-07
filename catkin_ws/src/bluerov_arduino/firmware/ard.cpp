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
std_msgs::Float32MultiArray water_pressure_message;
std_msgs::Float32MultiArray magnetometer_message;
std_msgs::Float32MultiArray imu_message;
ros::Publisher sensor_publisher("rovio/sensors", &sensor_message);
ros::Publisher water_pressure_publisher("rovio/water_pressure/data", &water_pressure_message);
ros::Publisher magnetometer_publisher("rovio/magnetometer/data", &magnetometer_message);
ros::Publisher imu_publisher("rovio/imu/data", &imu_message);

// Subscribers
 // Forward declaration
void enableThrustersCallback(const std_msgs::Bool& message);
void thrustersCallback(const std_msgs::UInt16MultiArray& message);
void calibrateMagnetometerOffsetsCallback(const std_msgs::Bool& message);
void calibrateGyroOffsetsCallback(const std_msgs::Bool& control_msg);
void calibrateAccelerometerOffsetsCallback(const std_msgs::Bool& message);
void waterPressureLoopRateCallback(const std_msgs::Float32& message);
void magnetometerLoopRateCallback(const std_msgs::Float32& message);
void imuLoopRateCallback(const std_msgs::Float32& message);

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
                water_pressuer_sample_time_subscriber("rovio/water_pressure/sample_time",
                                              &waterPressureLoopRateCallback);
ros::Subscriber<std_msgs::Float32>
                magnetometer_sample_time_subscriber("rovio/magnetometer/sample_time",
                                              &magnetometerLoopRateCallback);
ros::Subscriber<std_msgs::Float32>
                imu_sample_time_subscriber("rovio/imu/sample_time",
                                              &imuLoopRateCallback);

// Internal objects
ROVServo rov_servo;
MS5837 water_pressure_sensor;
MS5611 air_pressure_sensor(40);
MPU6000 imu(53);
HMC5883L magnetometer;

uint32_t water_pressure_last_call;
uint32_t magnetometer_last_call;
uint32_t imu_last_call;
float pressure_offset;
float water_pressure_sample_time = 0.03; // Can handle apporx 20 Hz
float magnetometer_sample_time = 0.01; // Can handle apporx 130 Hz
float imu_sample_time = 0.008; // Can handle apporx 200 Hz
bool calibrating = false;
/******************************************************************************
*       Functions                                                             *
*******************************************************************************/
void sendWaterPressure() {
  water_pressure_message.data[0] = millis();
  water_pressure_message.data[1] = water_pressure_sensor.pressure() - pressure_offset;
  water_pressure_publisher.publish(&water_pressure_message);
}

void sendMagnetometer() {
  float x,y,z;
  magnetometer_message.data[0] = millis();
  magnetometer.magneticField(x,y,z);
  magnetometer_message.data[1] = x;
  magnetometer_message.data[2] = y;
  magnetometer_message.data[3] = z;
  magnetometer_publisher.publish(&magnetometer_message);
}

void sendImu() {
  float x,y,z;
  imu_message.data[0] = millis();
  imu.gyro(x,y,z);
  imu_message.data[1] = x;
  imu_message.data[2] = y;
  imu_message.data[3] = z;
  imu.accel(x,y,z);
  imu_message.data[4] = x;
  imu_message.data[5] = y;
  imu_message.data[6] = z;

  imu_publisher.publish(&imu_message);
}

bool rate(uint32_t& last_call, const float sample_time) {
  uint32_t time_diff = millis() - last_call;
  float period = sample_time*1000;
  if ( time_diff < period) {
      return false;
  }

  last_call = millis();
  return true;
}

void spin() {

  if (rate(water_pressure_last_call, water_pressure_sample_time)) {
    if(water_pressure_sensor.read()) {
      sendWaterPressure();
    }
  }

  if (rate(imu_last_call, imu_sample_time)) {
    if (imu.read()) {
      sendImu();
    }
  }

  if (rate(magnetometer_last_call, magnetometer_sample_time)) {
    if (magnetometer.read()){
      sendMagnetometer();
    }
  }

}

int16_t readEEPROMInt16(uint16_t address) {
  uint8_t high = 0;
  uint8_t low = 0;
  high = EEPROM.read(address); // high bits
  low = EEPROM.read(address+1);

  return (high << 8) | low;
}


void rosDelay(uint32_t sleep_msec) {
  uint32_t wake_up_time = millis() + sleep_msec;

  while (wake_up_time > millis()) {
    nh.spinOnce();
  }
}

/******************************************************************************
*       Callbacks                                                             *
*******************************************************************************/
void enableThrustersCallback(const std_msgs::Bool& message) {
  if (message.data) {
    YELLOW_LED_OFF;
  } else {
    YELLOW_LED_ON;
  }

  rov_servo.resetThrusters(); // Reset the thrusters
  rov_servo.enableThrusters(message.data);
}

void thrustersCallback(const std_msgs::UInt16MultiArray& message) {
  uint16_t pwm_array[6];
  for (uint8_t i = 0; i < 6; i++) {
    pwm_array[i] = message.data[i];
  }
  rov_servo.setThrusters(pwm_array);
}

void calibrateMagnetometerOffsetsCallback(const std_msgs::Bool& message) {
  if (!calibrating) {
    calibrating = true;
    char log_msg[24];
    char str_temp[8];
    YELLOW_LED_ON;
    RED_LED_ON;
    BLUE_LED_ON;
    nh.logwarn("Move the magnetometer in circles while rotating it for 30s");
    rosDelay(5000);
    float min_max_field[6] = {5000,-5000,5000,-5000,5000,-5000};
    uint32_t stop_time = millis() + 30000;
    while (stop_time > millis()) {
      nh.spinOnce();
      magnetometer.calibrateOffsets(min_max_field,false);
    }
    magnetometer.calibrateOffsets(min_max_field,true);
    nh.loginfo("Magnetometer calibrated");
    float val;
    float scale = magnetometer.getScaling();
    val = scale*readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_X);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"x offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Y);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"y offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_MAGNETOMETER_OFFSET_Z);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"z offset: %s", str_temp);
    nh.loginfo(log_msg);
    YELLOW_LED_OFF;
    RED_LED_OFF;
    BLUE_LED_OFF;
    calibrating = false;
  }
}

void calibrateGyroOffsetsCallback(const std_msgs::Bool& message) {
  if (!calibrating) {
    calibrating = true;
    YELLOW_LED_ON;
    RED_LED_ON;
    BLUE_LED_ON;
    char log_msg[24];
    char str_temp[8];
    float val;
    nh.logwarn("Hold gyro still");
    rosDelay(5000);
    imu.calibrateGyroOffsets();
    nh.loginfo("Calculated offset in sensor frame");

    float scale = imu.getGyroScaling();
    val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_X);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"x offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_Y);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"y offset: %s", str_temp);
    nh.loginfo(log_msg);
    val = scale*readEEPROMInt16(EEPROM_GYRO_OFFSET_Z);
    dtostrf(val, 5, 2, str_temp);
    sprintf(log_msg,"z offset: %s", str_temp);
    nh.loginfo(log_msg);

    YELLOW_LED_OFF;
    RED_LED_OFF;
    BLUE_LED_OFF;
    calibrating = false;
  }
}

void calibrateAccelerometerOffsetsCallback(const std_msgs::Bool& message) {
  if (!calibrating) {
    calibrating = true;
    bool success = false;
    YELLOW_LED_ON;
    RED_LED_ON;
    BLUE_LED_ON;
    char log_msg[24];
    char str_temp[8];
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
      rosDelay(5000);
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
      dtostrf(val, 5, 2, str_temp);
      sprintf(log_msg,"x offset: %s", str_temp);
      nh.loginfo(log_msg);
      val = scale*readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Y);
      dtostrf(val, 5, 2, str_temp);
      sprintf(log_msg,"y offset: %s", str_temp);
      nh.loginfo(log_msg);
      val = scale*readEEPROMInt16(EEPROM_ACCELOMETER_OFFSET_Z);
      dtostrf(val, 5, 2, str_temp);
      sprintf(log_msg,"z offset: %s", str_temp);
      nh.loginfo(log_msg);
    }
    YELLOW_LED_OFF;
    RED_LED_OFF;
    BLUE_LED_OFF;
    calibrating = false;
  }
}

void waterPressureLoopRateCallback(const std_msgs::Float32& message) {
  water_pressure_sample_time = message.data/3; // It has 3 read cycles
}

void magnetometerLoopRateCallback(const std_msgs::Float32& message) {
  magnetometer_sample_time = message.data;
}

void imuLoopRateCallback(const std_msgs::Float32& message) {
  imu_sample_time = message.data;
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

  water_pressure_message.data_length = 2;
  water_pressure_message.layout.dim[0].size = water_pressure_message.data_length;
  water_pressure_message.layout.dim[0].stride = 1*water_pressure_message.data_length;
  water_pressure_message.layout.dim[0].label = "Water pressure";
  water_pressure_message.data = (float*)malloc(sizeof(float)*water_pressure_message.data_length);

  magnetometer_message.data_length = 4;
  magnetometer_message.layout.dim[0].size = magnetometer_message.data_length;
  magnetometer_message.layout.dim[0].stride = 1*magnetometer_message.data_length;
  magnetometer_message.layout.dim[0].label = "Water pressure";
  magnetometer_message.data = (float*)malloc(sizeof(float)*magnetometer_message.data_length);

  imu_message.data_length = 7;
  imu_message.layout.dim[0].size = imu_message.data_length;
  imu_message.layout.dim[0].stride = 1*imu_message.data_length;
  imu_message.layout.dim[0].label = "Water pressure";
  imu_message.data = (float*)malloc(sizeof(float)*imu_message.data_length);

  nh.getHardware()->setBaud(115200); //115200
  nh.initNode();
  nh.advertise(water_pressure_publisher);
  nh.advertise(magnetometer_publisher);
  nh.advertise(imu_publisher);
  nh.subscribe(enable_thrusters_subscriber);
  nh.subscribe(thrusters_subscriber);
  nh.subscribe(calibrate_magnetometer_offsets_subscriber);
  nh.subscribe(calibrate_gyro_offsets_subscriber);
  nh.subscribe(calibrate_accelerometer_offsets_subscriber);
  nh.subscribe(water_pressuer_sample_time_subscriber);
  nh.subscribe(magnetometer_sample_time_subscriber);
  nh.subscribe(imu_sample_time_subscriber);

  while(!nh.connected()){
    nh.spinOnce();
  }

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

  rov_servo.init();
  nh.loginfo("Setup complete");
  water_pressure_last_call = magnetometer_last_call = imu_last_call = millis();
  RED_LED_OFF;
  YELLOW_LED_ON;
}

void loop() {
  spin();
  nh.spinOnce();
}
