/*
 * File: liurov/include/teleop_xbox.h
 * Author: Erik Ekelund, based on code from Bluerobotics blurovpkg
 * Date: Jan 2016
 * Description: Headerfile for teleop_xbox.
 */
#include <math.h>
#include <ros/ros.h>
#include <ros/console.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Bool.h>
#include <dynamic_reconfigure/server.h>
#include <liurov/teleop_xboxConfig.h>

class TeleopXbox {
  public:
    TeleopXbox();
    void spin();

  private:
    ros::NodeHandle nh;
    ros::Publisher cmd_vel_pub;
    ros::Publisher hazard_enable_pub;
    ros::Subscriber joy_sub;

    dynamic_reconfigure::Server<liurov::teleop_xboxConfig> server;
    liurov::teleop_xboxConfig config;

    bool initLT;
    bool initRT;

    void configCallback(liurov::teleop_xboxConfig &update, uint32_t level);
    void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
    double computeAxisValue(const sensor_msgs::Joy::ConstPtr& joy, int index, double expo);
};
