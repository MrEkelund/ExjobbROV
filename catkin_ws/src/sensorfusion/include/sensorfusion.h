#include <ros/ros.h>
#include <ros/console.h>
#include <ros/time.h>
#include <dynamic_reconfigure/server.h>
#include <sensorfusion/ekfConfig.h>
#include <math.h>
#include <iostream>
#include "../include/Eigen/Dense"
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float32.h>
#include "std_msgs/MultiArrayDimension.h"
#include <std_msgs/Bool.h>

class Ekf {
public:
  Ekf();
  void calcHAcc();
  void calcHMag();
  void calcHPressure();
  void calcGv();
  void calcF();
  void accUpdate();
  void magUpdate();
  void pressureUpdate();
  void timeUpdate(double);
  void normQuaternions();

  void initFilter();
  void setRMag();
  void setRAcc();
  void setRPressure();
  void setQ();
  void setInitialStates();
  void setP0();
  void setInitiaMeasurements();
  void sendStates();
  void spin();
  void restartFilter();

private:
  ros::NodeHandle node_handle;
  ros::Publisher states_pub;
  ros::Subscriber imu_data_sub;
  ros::Subscriber mag_data_sub;
  ros::Subscriber pressure_data_sub;
  ros::Subscriber restart_sub;
  ros::Subscriber calibrate_mag_sub;
  std_msgs::Float64MultiArray state_message;


  //callbacks and dynamic reconfigure
  dynamic_reconfigure::Server<sensorfusion::ekfConfig> server;
  sensorfusion::ekfConfig config;
  void configCallback(sensorfusion::ekfConfig &update, uint level);
  void imuCallback(const std_msgs::Float32MultiArray &msg);
  void pressureCallback(const std_msgs::Float32 &msg);
  void magCallback(const std_msgs::Float32MultiArray &msg);
  void restartCallback(const std_msgs::Bool &msg);
  void calibrateMagCallback(const std_msgs::Bool &msg);

  //defenitions of matrices
  Eigen::Matrix<double, 5, 1> initial_states;
  Eigen::Matrix<double, 5, 1> states;
  Eigen::Matrix<double, 4, 1> quaterinons;
  Eigen::Matrix<double, 3, 1> omega;

  Eigen::Matrix<double, 5, 5> f; //motion model
  Eigen::Matrix<double, 4, 4> q; //covariance for motion model
  Eigen::Matrix<double, 5, 4> gv; //noise propagation for motion model

  // covariannce of estimates
  Eigen::Matrix<double, 5, 5> p;
  Eigen::Matrix<double, 5, 5> p0;

  // variables that are used during Calculation of time difference between two imu readings
  double delta_t;
  double store_t;
  bool any_updates;

  //storage vectors for measurements
  Eigen::Matrix<double, 3, 1> meas_acc;
  Eigen::Matrix<double, 3, 1> meas_mag;
  Eigen::Matrix<double, 1, 1> meas_pressure;

  //
  Eigen::Matrix<double, 3, 3>  r_acc;
  Eigen::Matrix<double, 3, 3>  r_mag;
  Eigen::Matrix<double, 1, 1>  r_pressure;

  bool new_mag_data;
  bool new_imu_data;
  bool new_pressure_data;
  bool imu_first_data;

  //constants for magnetometer.
  double mag_n;
  double mag_e;
  double mag_d;
};
