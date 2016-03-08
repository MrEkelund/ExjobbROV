/*
 * File: bluerov/src/matlab_controller.cpp
 * Author: Adam Aili
 * Date: Jan 2016
 * Description: Connects MATLAB with dynamic reconfigure.
 */

#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <bluerov/matlab_controllerConfig.h>

class MatlabController {
  public:
    MatlabController();
    void spin();

  private:
    ros::NodeHandle nh;

    dynamic_reconfigure::Server<bluerov::matlab_controllerConfig> server;
    bluerov::matlab_controllerConfig config;


    void configCallback(bluerov::matlab_controllerConfig &update, uint32_t level);
};

MatlabController::MatlabController() {
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<bluerov::matlab_controllerConfig>::CallbackType f;
  f = boost::bind(&MatlabController::configCallback, this, _1, _2);
  server.setCallback(f);
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
  config = update;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "MatlabController");
  MatlabController MatlabController;
  MatlabController.spin();
  return 0;
}
