#include "controller.h"



Controller::Controller(){
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<controller::controllerConfig>::CallbackType f;
  f = boost::bind(&Controller::configCallback, this, _1, _2);
  server.setCallback(f);


  // setup subscribers and publishers
  states_sub = node_handle.subscribe("sensor_fusion/states", 50, &Controller::stateCallback, this);
  cmd_vel_sub = node_handle.subscribe("/cmd_vel", 50, &Controller::cmdVelCallback, this);

  control_message.data.resize(6);
}




int main(int argc, char **argv){
  ros::init(argc, argv, "Controller");
}
