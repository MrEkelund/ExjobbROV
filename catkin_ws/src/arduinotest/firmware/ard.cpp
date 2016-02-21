#include <ros.h>
#include <std_msgs/String.h>

#include <Arduino.h>
#include <Servo.h>

byte servoPin1 = 9;
byte servoPin2 = ;
byte servoPin3 = 9;
byte servoPin4 = 9;
byte servoPin5 = 9;
byte servoPin6 = 9;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// setup is where you run the code once

void setup() {
  Serial.begin(9600); //turn serial on
  servo.attach(9);

  servo.writeMicroseconds(1500); // send “stop” signal to ESC.
  delay(1000); // delay to allow the ESC to recognize the stopped signal
}

// main code here to run repeatedly
void loop() {
  int signal = 1700; // Set signal value, which should be between 1100 and 1900
  servo.writeMicroseconds(signal); // Send signal to ESC.
  if (Serial.available()) {
    signal = Serial.read();
    Serial.write(signal);
}


ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
