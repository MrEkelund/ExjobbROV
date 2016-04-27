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
  void calcF();
  void calcGv();
  void calcHAcc();
  void calcHPressure();
  void calcHMag();
  void calcHGyro();
  void accUpdate();
  void magUpdate();
  void gyroUpdate();
  void pressureUpdate();
  void timeUpdate();
  void normQuaternions();
	

  void initFilter();
  void setCovMag();
  void setCovAcc();
  void setCovPressure();
  void setCovGyro();
  void setProcessCov();
  void setInitialStates();
  void setInitialStateCov();
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

  //definitions of matrices
  Eigen::Matrix<double, 11, 1> initial_states;
  Eigen::Matrix<double, 11, 1> states;
  Eigen::Matrix<double, 11, 1> new_states;  // This variable is needed since eigen does not like asignments on the form a = a*b etc
  // initial covariance of states
  Eigen::Matrix<double, 11, 11> initial_state_cov;
  // covariance of states
  Eigen::Matrix<double, 11, 11> state_cov;
  Eigen::Matrix<double, 11, 11> new_state_cov; // This variable is needed since eigen does not like asignments on the form a = a*b etc

 //definitions of motion model related matrices
  Eigen::Matrix<double, 11, 11> F; // motion model jacobian F = d/d(xn) f(x_k)*x_k or  (Fossen terms:  eta_k+1 = T(eta_k)*nu_k where state = [eta;nu;];
  Eigen::Matrix<double, 11, 11> f; // motion model matrix on form x_k+1 = f(x_k)*x_k
  Eigen::Matrix<double, 11, 7> Gv; // noise propagation
  Eigen::Matrix<double, 7, 7> process_cov; //covariance for motion model aka. system noise.

//matrices for gyro measurement update
  Eigen::Matrix<double, 3, 11> H_gyro; // gyro measurement jacobian
  Eigen::Matrix<double, 3, 1> h_gyro;	// expected gyro measurement
  Eigen::Matrix<double, 3, 3> cov_gyro;

//matrices for acc measurement update
  Eigen::Matrix<double, 3, 11> H_acc; // acc measurement jacobian
  Eigen::Matrix<double, 3, 1> h_acc; // expected acc measurement
  Eigen::Matrix<double, 3, 3> cov_acc;

//matrices for magnetometer measurement update
  Eigen::Matrix<double, 3, 11> H_mag; //mag  measurement jacobian
  Eigen::Matrix<double, 3, 1> h_mag; // expected mag measurement
  Eigen::Matrix<double, 3, 3> cov_mag;
  double mag_n;
  double mag_e;
  double mag_d;

//matrices for pressure measurement update
  Eigen::Matrix<double, 1, 11> H_pressure; // Pressure measurement jacobian
  Eigen::Matrix<double, 1, 1> h_pressure; // expected pressure measurement
  Eigen::Matrix<double, 1, 1> cov_pressure;

  // variables that are used during Calculation of time difference between two imu readings
  double delta_t;
  double store_t;
  bool any_updates;

  //storage vectors for measurements
  Eigen::Matrix<double, 3, 1> meas_acc;
  Eigen::Matrix<double, 3, 1> meas_mag;
  Eigen::Matrix<double, 1, 1> meas_pressure;
  Eigen::Matrix<double, 3, 1> meas_gyro;

//booleans for main loop
  bool new_mag_data;
  bool new_imu_data;
  bool new_pressure_data;
  bool imu_first_data;
};
