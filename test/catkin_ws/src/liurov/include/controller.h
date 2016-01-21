/*
 * File: liurov/include/controller.h
 * Author: Erik Ekelund
 * Date: Jan 2016
 * Description: Headerfile for control node for liurov.
 */

 #include <math.h>
 #include <ros/ros.h>
 #include <ros/console.h>
 #include <geometry_msgs/Twist.h>
 #include <std_msgs/Bool.h>
 #include <dynamic_reconfigure/server.h>
 #include <liurov/controllerConfig.h>
 #include <iostream>

 class Controller {
   public:
     Controller();
     void spin();

   private:
     ros::NodeHandle nh;
     ros::Subscriber cmd_vel_sub;
     double reference[6];
     double states[13];

     dynamic_reconfigure::Server<liurov::controllerConfig> server;
     liurov::controllerConfig config;

     void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& new_reference);
     void configCallback(liurov::controllerConfig &update, uint32_t level);
     void statesCallback(const geometry_msgs::Twist::ConstPtr& );
};
