/*
 * File: bluerov/src/heartbeat_rovio.cpp
 * Author: Adam Aili
 * Date: Jan 2016
 * Description: Check that the external computer is connected with the arduino.
 */

#include <ros/ros.h>
#include <std_msgs/Bool.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "heartbeat_rovio");
  ros::NodeHandle nh;
  ros::Publisher heartbeat_publisher = nh.advertise<std_msgs::Bool>("/rovio/heartbeat", 1000);
  std_msgs::Bool msg;
  ros::Rate loop_rate(4);

  while(ros::ok()) {
    heartbeat_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }



  return 0;
}
