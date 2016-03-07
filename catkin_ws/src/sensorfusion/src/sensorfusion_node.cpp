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

        //parameters
        /*
        double sample_time;
        double config.g;
        RowVector3d mag_reference;
        double config.rho;

        // outlier rejection parameters
        double eps_acc;
        double eps_mag;
        double eps_pressure;

        bool enable_acc;
        bool enable_mag;
        */
        bool enable_pressure;



};

Ekf::Ekf(){
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<sensorfusion::ekfConfig>::CallbackType f;
  f = boost::bind(&Ekf::configCallback, this, _1, _2);
  server.setCallback(f);

};

void Ekf::configCallback(sensorfusion::ekfConfig &update, uint level){
  config=update;
};

void Ekf::pressureUpdate()
{
  if(config.enable_pressure && (meas_pressure(0) > 0))
  {
    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth

    Eigen::RowVectorXd h_pressure;
    h_pressure(0)=config.g*config.rho*(d - config.x_offset*(2*q0*q2 - 2*q1*q3));

//generated via script in matlab
    Eigen::MatrixXd H_pressure;
    H_pressure(0,0) = -2*config.g*q2*config.rho*config.x_offset;
    H_pressure(0,1) = 2*config.g*q3*config.rho*config.x_offset;
    H_pressure(0,2) = -2*config.g*q0*config.rho*config.x_offset;
    H_pressure(0,3) = 2*config.g*q1*config.rho*config.x_offset;
    H_pressure(0,4) = config.g*config.rho;

    measurementUpdate(H_pressure,h_pressure,r_pressure,meas_pressure);

  }

};

void Ekf::accUpdate(){
  if (config.enable_acceleration && (abs(meas_acc.norm() - config.g) < config.eps_acc)) {

    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth

    Eigen::RowVectorXd h_acc;
    h_acc(0)  = config.g*(q0*q2*2.0-q1*q3*2.0);
    h_acc(1)  = -config.g*(q0*q1*2.0+q2*q3*2.0);
    h_acc(2)  = -config.g*((q0*q0)*2.0+(q3*q3)*2.0-1.0);

  //generated via script in matlab
  Eigen::MatrixXd H_acc;
  H_acc(0,0) =2*config.g*q2; H_acc(0,1)=-2*config.g*q3; H_acc(0,2)=  2*config.g*q0; H_acc(0,3)=-2*config.g*q1, H_acc(0,4) = 0;
  H_acc(1,0) = -2*config.g*q1; H_acc(1,1) = -2*config.g*q0;  H_acc(1,2) = -2*config.g*q3; H_acc(1,3) = -2*config.g*q2;  H_acc(1,4) = 0;
  H_acc(2,0) = -4*config.g*q0; H_acc(2,1) = 0; H_acc(2,2) =0;  H_acc(2,3) =-4*config.g*q3,H_acc(2,4) = 0;


  measurementUpdate(H_acc,h_acc,r_acc,meas_acc);
  }
}

void Ekf::magUpdate(){
  if (config.enable_magnetometer && (abs(meas_mag.norm() - sqrt(config.mag_n*config.mag_n + config.mag_e*config.mag_e + config.mag_d*config.mag_d)) < config.eps_mag)) {

    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth


    Eigen::RowVectorXd h_mag;

    h_mag(0)= sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*((q0*q0)*2.0+(q1*q1)*2.0-1.0)-config.mag_d*(q0*q2*2.0-q1*q3*2.0);
    h_mag(1)= -(q0*q3*2.0-q1*q2*2.0)*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)+config.mag_d*(q0*q1*2.0+q2*q3*2.0);
    h_mag(2)= config.mag_d*((q0*q0)*2.0+(q3*q3)*2.0-1.0)+(q0*q2*2.0+q1*q3*2.0)*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n);

    Eigen::MatrixXd H_mag;
    H_mag(0,0) = q0*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*4.0-config.mag_d*q2*2.0;
    H_mag(0,1) = q1*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*4.0+config.mag_d*q3*2.0;
    H_mag(0,3)  = config.mag_d*q0*-2.0;
    H_mag(0,3) = config.mag_d*q1*2.0;
    H_mag(0,4) = 0;

    H_mag(1,0) = q3*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*-2.0+config.mag_d*q1*2.0;
    H_mag(1,1) = q2*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0+config.mag_d*q0*2.0;
    H_mag(1,2) = q1*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0+config.mag_d*q3*2.0;
    H_mag(1,3) = q0*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*-2.0+config.mag_d*q2*2.0;
    H_mag(1,4) = 0;

    H_mag(2,0) = q2*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0+config.mag_d*q0*4.0;
    H_mag(2,1) = q3*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0;
    H_mag(2,2) =q0*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0;
    H_mag(2,3) = q1*sqrt(config.mag_e*config.mag_e+config.mag_n*config.mag_n)*2.0+config.mag_d*q3*4.0;
    H_mag(2,4) =0;


  }
};




void Ekf::measurementUpdate(Eigen::MatrixXd H, Eigen::MatrixXd h, Eigen::MatrixXd r, Eigen::RowVectorXd measurements)
{
      Eigen::RowVectorXd innovation = measurements - h;
      Eigen::MatrixXd temp = (H*p*H.transpose() + r).inverse();
      Eigen::MatrixXd k = p*H*temp;

      Eigen::RowVectorXd new_states = states + k*innovation;
      states = new_states;

      Eigen::MatrixXd p_new = p - k*H*p;
      p = p_new;
}


int main()
{

}
