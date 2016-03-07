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
        void acc_update();
        void mag_update();
        void pressure_update();



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
        Eigen::RowVectorXd acc_meas;
        Eigen::RowVectorXd mag_meas;
        Eigen::RowVectorXd pressure_meas;

        //
        Eigen::MatrixXd r_acc;
        Eigen::MatrixXd r_mag;
        Eigen::MatrixXd r_pressure;

        //parameters
        /*
        double sample_time;
        double g;
        RowVector3d mag_reference;
        double rho;

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
  //dynamic_reconfigure::Server<sensorfusion::ekfConfig>::CallbackType f;
  //f = boost::bind(&Ekf::configCallback, this, _1, _2);
  //server.setCallback(f);

}
void Ekf::pressure_update()
{
  if(enable_pressure && (pressure_meas(0) > 0))
  {
    //calc innovation
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth
    double rho = 1000.0;
    double g = 9.82;
    double x_offset = 0.2;

    double h_pressure=g*rho*(d - x_offset*(2*q0*q2 - 2*q1*q3));
    Eigen::MatrixXd H_pressure;


    //
    H_pressure(0,0) = -2*g*q2*rho*x_offset; H_pressure(0,1) = 2*g*q3*rho*x_offset;
    H_pressure(0,2) =  -2*g*q0*rho*x_offset;
    H_pressure(0,3) = 2*g*q1*rho*x_offset;
    H_pressure(0,4) = g*rho;

    double innovation = pressure_meas(0) - h_pressure;
    Eigen::MatrixXd temp = (H_pressure*p*H_pressure.transpose() + r_pressure).inverse();
    Eigen::MatrixXd k = p*H_pressure*temp;


  }

}





int main()
{

}
