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
 #include <vector>
 #include <std_msgs/Bool.h>
 #include <dynamic_reconfigure/server.h>

 class Controller {
   public:
     Controller();
     void spin();

   private:
     ros::NodeHandle nh;
     ros::Subscriber cmd_vel_sub;
     double reference[6];

     void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& new_reference);
};
