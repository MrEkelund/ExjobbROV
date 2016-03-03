#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include "sensorfusion_types.h"


void convert_from_bus(std_msgs::Float32MultiArray* msgPtr, SL_Bus_sensorfusion_std_msgs_Float32MultiArray const* busPtr);
void convert_to_bus(SL_Bus_sensorfusion_std_msgs_Float32MultiArray* busPtr, std_msgs::Float32MultiArray const* msgPtr);

void convert_from_bus(std_msgs::Float64MultiArray* msgPtr, SL_Bus_sensorfusion_std_msgs_Float64MultiArray const* busPtr);
void convert_to_bus(SL_Bus_sensorfusion_std_msgs_Float64MultiArray* busPtr, std_msgs::Float64MultiArray const* msgPtr);

void convert_from_bus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_sensorfusion_std_msgs_MultiArrayDimension const* busPtr);
void convert_to_bus(SL_Bus_sensorfusion_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr);

void convert_from_bus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_sensorfusion_std_msgs_MultiArrayLayout const* busPtr);
void convert_to_bus(SL_Bus_sensorfusion_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr);


#endif
