#include <ros.h>
#include <std_msgs/String.h>

#include <Arduino.h>
#include <Servo.h>

#include "includes/ROVServo.h"

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

int pwm_array[6];
char hello[13] = "hello world!";

ROVServo rov_servo;

// setup is where you run the code once
void setup() {
  nh.initNode();
  nh.advertise(chatter);

  rov_servo.initROVServo();
  pwm_array[0] = 1550;
  pwm_array[1] = 1600;
  pwm_array[2] = 1650;
  pwm_array[3] = 1700;
  pwm_array[4] = 1750;
  pwm_array[5] = 1800;
}

void loop() {
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  rov_servo.setThrusters(pwm_array);
  delay(1000);
}

/*




char hello[13] = "hello world!";

void setup()
{

}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
*/
