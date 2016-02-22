#ifndef _ROV_IO_H_
#define _ROV_IO_H_

#include "defines.h"
#include "ROVServo.h"
#include "MS5837.h"

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt16MultiArray.h>

#include <Arduino.h>

class ROVIO
{
  public:
    ROVIO();
    void spin();

  private:
    void sendSensors();

    // Callback functions
    //void ROVIO::thrustersCallback(
    //  const std_msgs::UInt16MultiArray::ConstPtr& message);

    ros::NodeHandle _nh;

    // Publishers
    ros::Publisher* _sensor_publisher;

    // Subscribers
    //ros::Subscriber _thruster_subscriber;

    // Internal objects
    ROVServo _rov_servo;
    MS5837 _water_pressure_sensor;

    // Internal variables
    uint16_t _pwm_array[6];
  };

#endif //_ROV_IO_H_
