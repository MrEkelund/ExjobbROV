#include "controller.h"



Controller::Controller(): {
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<controller::controllerConfig>::CallbackType f;
  f = boost::bind(&Controller::configCallback, this, _1, _2);
  server.setCallback(f);


  // setup subscribers and publishers
  _states_sub = node_handle.
      subscribe("/sensor_fusion/states", 50, &Controller::stateCallback, this);
  _cmd_vel_sub = node_handle.
      subscribe("/cmd_vel", 50, &Controller::cmdVelCallback, this);
  _dec_inc_depth_sub = node_handle.
      subscribe("/dec_inc_depth_sub", 50, &Controller::decIncDepthCallback, this);

  _control_message.data.resize(6);
}

void Controller::calcJ() {

}

void Controller::calcJdot() {

}

void Controller::calcD() {

}

void Controller::calcC() {
}

void Controller::calcG() {

}

void Controller::configCallback(controller::controllerConfig &update, uint level) {
  _config = update;
}

void Controller::stateCallback(const std_msgs::Float64MultiArray &msg) {
  _euler_angles(0,0) = msg.data[0];
  _euler_angles(1,0) = msg.data[1];
  _euler_angles(2,0) = msg.data[2];
  _ang_vel(0,0) = msg.data[3];
  _ang_vel(1,0) = msg.data[4];
  _ang_vel(2,0) = msg.data[5];
  _depth(0,0) = msg.data[6];
}

void Controller::Controller::cmdVelCallback(const geometry_msgs::Twist &msg) {

  if (_config.xbox) {
    _velocity_ref(0,0) = msg.linear.x;
    _velocity_ref(1,0) = msg.linear.y;
    _velocity_ref(2,0) = msg.linear.z;
    _velocity_ref(3,0) = msg.angular.x;
    _velocity_ref(4,0) = msg.angular.y;
    _velocity_ref(5,0) = msg.angular.z;
  }
}

void Controller::Controller::decIncDepthCallback(const std_msgs::Float32 &msg) {
  _depth_ref(0,0) = _depth_ref(0,0) + 0.1*msg.data;
}

void Controller::calcRateControl() {

}
void Controller::calcAttitudeControl() {

}
void Controller::calcDepthControl() {

}
void Controller::calcDecControll() {

}

void Controller::setRate(int new_rate) {
  _ros_rate(new_rate);
}


void Controller::spin() {
  ros::Rate loop(config.pub_rate);

  while(ros::ok()) {
    ros::spinOnce();

    loop.sleep();
  }
}

int main(int argc, char **argv){
  ros::init(argc, argv, "Controller");
  Controller controller;
  controller.spin();
}
