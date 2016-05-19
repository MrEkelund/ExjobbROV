#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ros/ros.h>
#include <ros/console.h>
#include <ros/time.h>
#include <dynamic_reconfigure/server.h>
#include <dynamic_reconfigure/BoolParameter.h>
#include <dynamic_reconfigure/Reconfigure.h>
#include <dynamic_reconfigure/Config.h>
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


const double lx1 = 0.19;
const double  ly1 = 0.11;
const double  ly2 = 0.11;
const double  lx2 = 0.19;
const double  ly3 = 0.11;
const double  lx5 = 0.17;
const double  ly4 = 0.11;
const double  lz6 = 0;
const double  zb = -0.033120007018861;
const double  Kp = -0.832583865050131;
const double  Kp_abs_p = -0.493305055639320;
const double  Mq = -0.848713697434902;
const double  Mq_abs_q = -0.250737627230074;
const double  Nr = -1.758097465526971;
const double  Nr_abs_r = -1.459511824869412;
const double  Ix_Kp_dot = 0.602410402365800;
const double  Iy_Mq_dot = 0.783497332223251;
const double  Iz_Nr_dot = 1.399324614234730;
const double  m = 6.621;
const double  g = 9.81744;
const double B = m*g;

typedef struct {double x; double y;} thrustmap_t;

thrustmap_t thrustmap[76] = {
  {-40.0788,-1.0000},
  {-40.0337,-0.9500},
  {-37.5428,-0.9250},
  {-36.6092,-0.9000},
  {-35.4971,-0.8750},
  {-33.7623,-0.8500},
  {-32.3835,-0.8250},
  {-31.2263,-0.8000},
  {-29.9809,-0.7750},
  {-28.5128,-0.7500},
  {-27.6234,-0.7250},
  {-26.5554,-0.7000},
  {-24.7765,-0.6750},
  {-23.1751,-0.6500},
  {-22.1522,-0.6250},
  {-21.3510,-0.6000},
  {-19.5280,-0.5750},
  {-18.4600,-0.5500},
  {-17.3480,-0.5250},
  {-16.1025,-0.5000},
  {-14.6345,-0.4750},
  {-13.0781,-0.4500},
  {-12.1877,-0.4250},
  {-10.9874,-0.4000},
  {-10.0528,-0.3750},
  {-8.8966,-0.3500},
  {-7.7404,-0.3250},
  {-6.8058,-0.3000},
  {-6.0497,-0.2750},
  {-5.1151,-0.2500},
  {-4.2698,-0.2250},
  {-3.4696,-0.2000},
  {-2.7135,-0.1750},
  {-1.8682,-0.1500},
  {-1.1121,-0.1250},
  {-0.5335,-0.1000},
  {-0.2667,-0.0750},
  {0,0},
  {0.5786,0.0750},
  {1.1121,0.1000},
  {1.8240,0.1250},
  {2.5801,0.1500},
  {3.4255,0.1750},
  {4.0923,0.2000},
  {5.1151,0.2250},
  {6.2272,0.2500},
  {7.0284,0.2750},
  {8.2739,0.3000},
  {9.2526,0.3250},
  {10.8089,0.3500},
  {12.2328,0.3750},
  {13.6558,0.4000},
  {14.9904,0.4250},
  {16.4585,0.4500},
  {17.7039,0.4750},
  {19.2161,0.5000},
  {20.5508,0.5250},
  {21.7521,0.5500},
  {23.6644,0.5750},
  {24.7324,0.6000},
  {26.4221,0.6250},
  {27.7126,0.6500},
  {29.6249,0.6750},
  {31.3156,0.7000},
  {32.8729,0.7250},
  {33.8065,0.7500},
  {34.2517,0.7750},
  {37.0534,0.8000},
  {38.6549,0.8250},
  {39.2776,0.8500},
  {41.1458,0.8750},
  {42.9257,0.9000},
  {44.7938,0.9250},
  {47.1062,0.9500},
  {48.0408,0.9750},
  {49.9531,1.0000}
};

typedef struct {double start_time; double amplitude; double frequency;
  double bias; double speed; double final_value; double final_time;
  double constant; bool time_reached; bool enable; int reference_signal;} reference_t;

class Controller {
public:
  Controller();

  void spin();
private:
  ros::NodeHandle _node_handle;

  dynamic_reconfigure::Server<controller::controllerConfig> _server;
  controller::controllerConfig _config;

  void initT();
  void calcJ();
  void calcJdot();
  Eigen::Vector3d momentsNEDToBody(Eigen::Vector3d moments);
  void calcR();
  Eigen::Matrix<double, 6, 1> forcesNEDToBody(Eigen::Vector3d moments);
  void calcLinControl(Eigen::Matrix<double, 6, 1>& acc, Eigen::Matrix<double, 6, 1>& control_signals);
  void interpolate(const Eigen::Matrix<double, 6, 1>& moments, Eigen::Matrix<double, 6, 1>& control);

  void calcReferenceSignals();
  double calcStepReference(reference_t& ref_struct);
  double calcSinReference(reference_t& ref_struct);

  bool checkReferenceValues();
  void configCallback(controller::controllerConfig &update, uint level);
  void stateCallback(const std_msgs::Float64MultiArray &msg);
  void cmdVelCallback(const geometry_msgs::Twist &msg);
  void decIncDepthCallback(const std_msgs::Float32 &msg);

  Eigen::Matrix<double, 6, 1> calcRateControl();
  Eigen::Matrix<double, 6, 1> calcAttitudeControl();
  Eigen::Matrix<double, 6, 1> calcDepthControl();
  Eigen::Matrix<double, 6, 1> calcDecControll();


  void sendThrusterSignals(Eigen::Matrix<double, 6,1>&);
  void sendReferenceSignals();

  Eigen::Vector3d _ang_vel;
  Eigen::Vector3d _euler_angles;
  double _depth;
  Eigen::Vector3d _ang_vel_ref;
  Eigen::Vector3d _velocity_ref;
  Eigen::Vector3d _euler_angles_ref;
  double _depth_ref;

  Eigen::Matrix<double, 6, 6> _T;
  Eigen::Matrix<double, 3, 3> _J;
  Eigen::Matrix<double, 3, 3> _J_dot;
  Eigen::Matrix<double, 3, 3> _R;

  Eigen::Vector3d _rate_integral;
  Eigen::Vector3d _attitude_integral;
  double _depth_integral;

  double _cphi;
  double _sphi;
  double _cth;
  double _sth;
  double _tth;
  double _cpsi;
  double _spsi;
  double _reference_t0;
  bool _reference_started;
  double _loop_rate;

  reference_t _phi_reference;
  reference_t _theta_reference;
  reference_t _psi_reference;
  reference_t _p_reference;
  reference_t _q_reference;
  reference_t _r_reference;
  reference_t _d_reference;

  ros::Subscriber _states_sub;
  ros::Subscriber _cmd_vel_sub;
  ros::Subscriber _dec_inc_depth_sub;
  ros::Publisher _control_pub;
  ros::Publisher _reference_pub;
};
#endif // CONTROLLER_H
