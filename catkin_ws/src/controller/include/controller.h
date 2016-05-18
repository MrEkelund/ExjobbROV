#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ros/ros.h>
#include <ros/console.h>
#include <ros/time.h>
#include <dynamic_reconfigure/server.h>
// requires catkin_make --pkg sensorfusion first. Else it wont find controllerConfig.h
#include <controller/controllerConfig.h>
#include <math.h>
#include <iostream>
#include "../include/Eigen/Dense"
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>
#include "std_msgs/MultiArrayDimension.h"
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

class Controller {
public:
  Controller();

  void spin();
private:
  ros::NodeHandle node_handle;

  dynamic_reconfigure::Server<controller::controllerConfig> server;
  controller::controllerConfig _config;

  std_msgs::UInt16MultiArray _control_message;



  void calcJ();
  void calcJdot();
  void calcD();
  void calcC();
  void calcG();
  void configCallback(controller::controllerConfig &update, uint level);
  void stateCallback(const std_msgs::Float64MultiArray &msg);
  void cmdVelCallback(const geometry_msgs::Twist &msg);
  void decIncDepthCallback(const std_msgs::Float32 &msg);
  void calcRateControl();
  void calcAttitudeControl();
  void calcDepthControl();
  void calcDecControll();

  Eigen::Matrix<double, 3, 1> _ang_vel;
  Eigen::Matrix<double, 3, 1> _euler_angles;
  Eigen::Matrix<double, 1, 1> _depth;
  Eigen::Matrix<double, 3, 1> _ang_ref;
  Eigen::Matrix<double, 6, 1> _velocity_ref;
  Eigen::Matrix<double, 1, 1> _depth_ref;

  ros::Subscriber _states_sub;
  ros::Subscriber _cmd_vel_sub;
  ros::Subscriber _dec_inc_depth_sub;
  ros::Publisher _controll_pub;
};
#endif // CONTROLLER_H
