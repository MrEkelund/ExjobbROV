#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <mavros_msgs/ActuatorControl.h>
#include <ros/time.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Header.h>
#include "Controller_with_out_ref_types.h"


void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convert_from_bus(geometry_msgs::Twist* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Twist const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(mavros_msgs::ActuatorControl* msgPtr, SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl* busPtr, mavros_msgs::ActuatorControl const* msgPtr);

void convert_from_bus(ros::Time* msgPtr, SL_Bus_Controller_with_out_ref_ros_time_Time const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convert_from_bus(sensor_msgs::Imu* msgPtr, SL_Bus_Controller_with_out_ref_sensor_msgs_Imu const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr);

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_Controller_with_out_ref_std_msgs_Header const* busPtr);
void convert_to_bus(SL_Bus_Controller_with_out_ref_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
