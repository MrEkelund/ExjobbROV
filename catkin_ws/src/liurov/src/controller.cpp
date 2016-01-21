#include <controller.h>

Controller::Controller() {
  for (int i = 0; i < 6; i++) {
    reference[i]=0;
  }

  // connect dynamic reconfigure
  dynamic_reconfigure::Server<liurov::controllerConfig>::CallbackType f;
  f = boost::bind(&Controller::configCallback, this, _1, _2);
  server.setCallback(f);

  // connects subs and pub
  cmd_vel_sub = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &Controller::cmdVelCallback, this);
};

void Controller::spin() {
  ros::Rate loop(config.pub_rate);

  while(ros::ok()) {
    // call all waiting callbacks
    ros::spinOnce();

    // enforce a max publish rate
    loop.sleep();
  }
}
void Controller::cmdVelCallback(const geometry_msgs::Twist::ConstPtr& new_reference)
{
  //copy linear velocities x y z
  reference[0] = new_reference->linear.x;
  reference[1] = new_reference->linear.y;
  reference[2] = new_reference->linear.z;
  //copy angular velocities p q r
  reference[3] = new_reference->angular.x;
  reference[4] = new_reference->angular.y;
  reference[5] = new_reference->angular.z;
  std::cout << "Received data" << std::endl;
}

void Controller::statesCallback(const geometry_msgs::Twist::ConstPtr& ){
  //copy states from sensorfusion node

}

void Controller::configCallback(liurov::controllerConfig &update, uint32_t level) {
  ROS_INFO("reconfigure request received");
  config = update;
}


int main(int argc, char** argv) {
  ros::init(argc, argv, "controller");
  Controller controller;

  controller.spin();
  return 0;
}
