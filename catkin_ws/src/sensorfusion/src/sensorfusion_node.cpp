//#include "sensorfusion.h"
#include <ros/ros.h>
#include <ros/console.h>
#include <ros/time.h>
#include <dynamic_reconfigure/server.h>
#include <sensorfusion/ekfConfig.h>
#include <cmath>
#include <iostream>
#include "../include/Eigen/Dense"


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
  void measurementUpdate(Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::RowVectorXd);
  void timeUpdate(double);
  void normQuaternions();

  void setRMag();
  void setRAcc();
  void setRPressure();
  void setQ();
  void setInitialStates();

private:
  ros::NodeHandle node_handle;
  ros::Publisher states_pub;
  ros::Subscriber imu_data_sub;
  ros::Subscriber mag_data_sub;
  ros::Subscriber pressure_data_sub;

  dynamic_reconfigure::Server<sensorfusion::ekfConfig> server;
  sensorfusion::ekfConfig config;
  void configCallback(sensorfusion::ekfConfig &update, uint level);



  //defenitions of matrices
  Eigen::RowVectorXd initial_states;
  Eigen::RowVectorXd states;
  Eigen::RowVectorXd quaterinons;
  Eigen::RowVectorXd omega;

  Eigen::MatrixXd f; //motion model
  Eigen::MatrixXd q; //covariance for motion model
  Eigen::MatrixXd gv; //noise propagation for motion model

  Eigen::MatrixXd p;
  Eigen::MatrixXd p0;

  //storage vectors for measurements
  Eigen::RowVectorXd meas_acc;
  Eigen::RowVectorXd meas_mag;
  Eigen::RowVectorXd meas_pressure;

  //
  Eigen::MatrixXd r_acc;
  Eigen::MatrixXd r_mag;
  Eigen::MatrixXd r_pressure;



};

Ekf::Ekf(){
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<sensorfusion::ekfConfig>::CallbackType f;
  f = boost::bind(&Ekf::configCallback, this, _1, _2);
  server.setCallback(f);

};

void Ekf::configCallback(sensorfusion::ekfConfig &update, uint level){
  config=update;
  setRMag();
  setRAcc();
  setRPressure();
  setQ();
  setInitialSta1
void Ekf::setRMag(){
  r_mag(0,0) = config.r_mag_00;
  r_mag(0,1) = 0.0;
  r_mag(0,2) = 0.0;

  r_mag(1,0) = 0.0;
  r_mag(1,1) = config.r_mag_11;
  r_mag(1,2) = 0.0;

  r_mag(2,0) = 0.0;
  r_mag(2,1) = 0.0;
  r_mag(2,2) = config.r_mag_22;
};


void Ekf::setRAcc(){
  r_acc(0,0) = config.r_acc_00;
  r_acc(0,1) = 0.0;
  r_acc(0,2) = 0.0;

  r_acc(1,0) = 0.0;
  r_acc(1,1) = config.r_acc_11;
  r_acc(1,2) = 0.0;

  r_acc(2,0) = 0.0;
  r_acc(2,1) = 0.0;
  r_acc(2,2) = config.r_acc_22;
};

void Ekf::setRPressure(){
  r_pressure(0,0) = config.r_pressure;
};

void Ekf::setQ(){
  q(0,0) = config.q_00;
  q(0,1) = 0.0;
  q(0,2) = 0.0;1
  q(1,0) = 0.0;
  q(1,1) = config.q_11;
  q(1,2) = 0.0;
  q(1,3) = 0.0;

  q(2,0) = 0.0;
  q(2,1) = 0.0;
  q(2,2) = config.q_22;
  q(2,3) = 0.0;

  q(3,0) = 0.0;
  q(3,1) = 0.0;
  q(3,2) = 0.0;
  q(3,3) = config.q_33;
}

void Ekf::setInitialStates(){
  initial_states(0) = config.initial_q0;
  initial_states(1) = config.initial_q1;
  initial_states(2) = config.initial_q2;
  initial_states(3) = config.initial_q3;
  initial_states(4) = config.initial_d;
}1


void Ekf::pressureUpdate()
{
  if(config.enable_pressure && (meas_pressure(0) > 0))
  {
    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth
    double g = config.g;
    double rho = config.rho;
    double x_offset = config.x_offset;
    Eigen::RowVectorXd h_pressure;

    h_pressure(0)=g*rho*(d - x_offset*(2*q0*q2 - 2*q1*q3));

    //generated via script in matlab
    Eigen::MatrixXd H_pressure;
    H_pressure(0,0) = -2*g*q2*rho*x_offset;
    H_pressure(0,1) = 2*g*q3*rho*x_offset;
    H_pressure(0,2) = -2*g*q0*rho*x_offset;
    H_pressure(0,3) = 2*g*q1*rho*x_offset;
    H_pressure(0,4) = g*rho;

    measurementUpdate(H_pressure,h_pressure,r_pressure,meas_pressure);

  }

};
//Calculation of h and H matrix for accelerometer measurement update
void Ekf::accUpdate(){
  double g = config.g;

  if (config.enable_acceleration && (abs(meas_acc.norm() - g) < config.eps_acc)) {

    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth

    // calculate predicted measurements
    Eigen::RowVectorXd h_acc;
    h_acc(0)  = g*(q0*q2*2.0-q1*q3*2.0);
    h_acc(1)  = -g*(q0*q1*2.0+q2*q3*2.0);
    h_acc(2)  = -g*((q0*q0)*2.0+(q3*q3)*2.0-1.0);

    //generated via script in matlab
    Eigen::MatrixXd H_acc;
    H_acc(0,0) = 2*g*q2; H_acc(0,1) = -2*g*q3; H_acc(0,2) =  2*g*q0; H_acc(0,3) = -2*g*q1, H_acc(0,4) = 0.0;
    H_acc(1,0) = -2*g*q1; H_acc(1,1) = -2*g*q0;  H_acc(1,2) = -2*g*q3; H_acc(1,3) = -2*g*q2;  H_acc(1,4) = 0.0;
    H_acc(2,0) = -4*g*q0; H_acc(2,1) = 0.0; H_acc(2,2) = 0.0;  H_acc(2,3) = -4*g*q3,H_acc(2,4) = 0.0;


    measurementUpdate(H_acc,h_acc,r_acc,meas_acc);
  }
};

//Calculation of h and H matrix for magnetometer measurement update
void Ekf::magUpdate(){
  double mag_n = config.mag_n;
  double mag_e = config.mag_e;
  double mag_d = config.mag_d;

  if (config.enable_magnetometer && (abs(meas_mag.norm() - sqrt(mag_n*mag_n + mag_e*mag_e + mag_d*mag_d)) < config.eps_mag)) {

    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth


    Eigen::RowVectorXd h_mag;
    // calculate predicted measurements
    h_mag(0)= sqrt(mag_e*mag_e+mag_n*mag_n)*((q0*q0)*2.0+(q1*q1)*2.0-1.0)-mag_d*(q0*q2*2.0-q1*q3*2.0);
    h_mag(1)= -(q0*q3*2.0-q1*q2*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n)+mag_d*(q0*q1*2.0+q2*q3*2.0);
    h_mag(2)= mag_d*((q0*q0)*2.0+(q3*q3)*2.0-1.0)+(q0*q2*2.0+q1*q3*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n);

    Eigen::MatrixXd H_mag;
    H_mag(0,0) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0-mag_d*q2*2.0;
    H_mag(0,1) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0+mag_d*q3*2.0;
    H_mag(0,3)  = mag_d*q0*-2.0;
    H_mag(0,3) = mag_d*q1*2.0;
    H_mag(0,4) = 0.0;

    H_mag(1,0) = q3*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*q1*2.0;
    H_mag(1,1) = q2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q0*2.0;
    H_mag(1,2) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q3*2.0;
    H_mag(1,3) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*q2*2.0;
    H_mag(1,4) = 0.0;

    H_mag(2,0) = q2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q0*4.0;
    H_mag(2,1) = q3*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
    H_mag(2,2) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
    H_mag(2,3) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q3*4.0;
    H_mag(2,4) =0.0;

    measurementUpdate(H_mag,h_mag,r_mag,meas_mag);

  }
};
void Ekf::timeUpdate(double T){
  //read states
  double q0 = states(0); double q1 = states(1);
  double q2 = states(2); double q3 = states(3);
  double wx = omega(0); double wy = omega(1); double wz = omega(2);
  //calculate f matrix
  f(0,0) = 1.0;
  f(0,1) = T*wx*(-1.0/2.0);
  f(0,2) = T*wy*(-1.0/2.0);
  f(0,3) = T*wz*(-1.0/2.0);
  f(0,4) = 0.0;

  f(1,0) = T*wx*(1.0/2.0);
  f(1,1) = 1.0;
  f(1,2) = T*wz*(1.0/2.0);
  f(1,3) = T*wy*(-1.0/2.0);
  f(1,4) = 0.0;

  f(2,0) = T*wy*(1.0/2.0);
  f(2,1) = T*wz*(-1.0/2.0);
  f(2,2) = 1.0;
  f(2,3) = T*wx*(1.0/2.0);
  f(2,4) = 0.0;

  f(3,0) = T*wz*(1.0/2.0);
  f(3,1) = T*wy*(1.0/2.0);
  f(3,2) = T*wx*(-1.0/2.0);
  f(3,3) = 1.0;
  f(3,4) = 0.0;

  f(4,0) = 0.0;
  f(4,1) = 0.0;
  f(4,2) = 0.0;
  f(4,3) = 0.0;
  f(4,4) = 1.0;


//calculate gv matrix
  gv(0,0) = T*q1*(-1.0/2.0);
  gv(0,1) = T*q2*(-1.0/2.0);
  gv(0,2) = T*q3*(-1.0/2.0);
  gv(0,3) = 0.0;

  gv(1,0) = T*q0*(1.0/2.0);
  gv(1,1) = T*q3*(-1.0/2.0);
  gv(1,2) = T*q2*(1.0/2.0);
  gv(1,3) = 0.0;

  gv(2,0) = T*q3*(1.0/2.0);
  gv(2,1) = T*q0*(1.0/2.0);
  gv(2,2) = T*q1*(-1.0/2.0);
  gv(2,3) = 0;

  gv(3,0) = T*q2*(-1.0/2.0);
  gv(3,1) = T*q1*(1.0/2.0);
  gv(3,2) = T*q0*(1.0/2.0);
  gv(3,3) = 0.0;

  gv(4,0) = 0.0;
  gv(4,1) = 0.0;
  gv(4,2) = 0.0;
  gv(4,3) = 1.0;

  // time update
  Eigen::RowVectorXd new_states = f*states;
  states = new_states;

  //update P
  Eigen::MatrixXd p_new = f*p*f.transpose() + gv*q*gv.transpose();
  p  = p_new;

};


void Ekf::measurementUpdate(Eigen::MatrixXd H, Eigen::MatrixXd h, Eigen::MatrixXd r, Eigen::RowVectorXd measurements){
  Eigen::RowVectorXd innovation = measurements - h;
  Eigen::MatrixXd temp = (H*p*H.transpose() + r).inverse();
  Eigen::MatrixXd k = p*H*temp;

  Eigen::RowVectorXd new_states = states + k*innovation;
  states = new_states;

  Eigen::MatrixXd p_new = p - k*H*p;
  p = p_new;
  normQuaternions();
};

void Ekf::normQuaternions(){
  Eigen::RowVectorXd store;
  store(0) = states(0);
  store(1) = states(1);
  store(2) = states(2);
  store(3) = states(3);
  double normfactor = store.norm();

  double sign = (states(0) > 0)-(states(0) < 0);
  states(0) = states(0)*sign/normfactor;
  states(1) = states(1)*sign/normfactor;
  states(2) = states(2)*sign/normfactor;
  states(3) = states(3)*sign/normfactor;
};

int main()
{

};
