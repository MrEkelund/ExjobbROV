#include <ros/ros.h>
#include <ros/console.h>
#include <ros/time.h>
#include <dynamic_reconfigure/server.h>
// requires catkin_make --pkg sensorfusion first. Else it wont find ekfConfig.h
#include <controller/controllerConfig.h>
#include <math.h>
#include <iostream>
#include "../include/Eigen/Dense"
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>
#include "std_msgs/MultiArrayDimension.h"
#include <std_msgs/Bool.h>

class Controller {
public:
private:
  ros::NodeHandle node_handle;

  ros::Subscriber states_pub;
  ros::Subscriber cmd_vel_sub;
  ros::Publisher controll_pub;

  std_msgs::UInt16MultiArray control_message;



  void calcJ();
  void calcJdot();
  void calcD();
  void calcC();
  void calcG();
  void Controller::stateCallback(const std_msgs::Float64MultiArray &msg);
  void Controller::cmdVelCallback(const geometry_msgs::Twist &msg);
  void calcRateControl();
  void calcAttitudeControl();
  void calcDepthControl();
  void calcDecControll();


  Eigen::Matrix<double, 3, 1> ang_vel;
  Eigen::Matrix<double, 3, 1> euler_angles;
  Eigen::Matrix<double, 1, 1> depth;

}
