/*
 * File: bluerov/src/matlab_controller.cpp
 * Author: Adam Aili
 * Date: Jan 2016
 * Description: Connects MATLAB with dynamic reconfigure.
 */

#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <bluerov/matlab_controllerConfig.h>
//#include <bluerov/pid_parametersConfig.h>

class MatlabController {
  public:
    MatlabController();
    void spin();

  private:
    ros::NodeHandle nh;

    dynamic_reconfigure::Server<bluerov::matlab_controllerConfig> server;
    //dynamic_reconfigure::Server<bluerov::pid_parametersConfig> pidserver;
    bluerov::matlab_controllerConfig config;
    //bluerov::pid_parametersConfig pidconfig;

    void configCallback(bluerov::matlab_controllerConfig &update, uint32_t level);
  //  void pidCallback(bluerov::pid_parametersConfig &update, uint32_t level);
};

MatlabController::MatlabController() {
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<bluerov::matlab_controllerConfig>::CallbackType f;
  f = boost::bind(&MatlabController::configCallback, this, _1, _2);
  server.setCallback(f);

/*  dynamic_reconfigure::Server<bluerov::pid_parametersConfig>::CallbackType h;
  h = boost::bind(&MatlabController::pidCallback, this, _1, _2);
  pidserver.setCallback(h);*/
}

void MatlabController::spin() {
  // enforce a max spin rate so we don't kill the CPU
  ros::Rate loop(2); // Hz

  while(ros::ok()) {
    // call all waiting callbacks
    ros::spinOnce();
    loop.sleep();
  }
}

void MatlabController::configCallback(bluerov::matlab_controllerConfig &update, uint32_t level) {
  ROS_INFO("CONTROLLER reconfigure request received");
  config = update;
}

/*void MatlabController::pidCallback(bluerov::pid_parametersConfig &update, uint32_t level) {
  ROS_INFO("PID reconfigure request received");
  pidconfig = update;
}*/

int main(int argc, char** argv) {
  ros::init(argc, argv, "MatlabController");
  MatlabController MatlabController;
  MatlabController.spin();
  return 0;
}
