#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)

echo -e "Enter the name you want for the logfile" 
read name
cd ../simulink/Estimation/bag
rosbag record -o $name sensor_fusion/states rovio/water_pressure/data rovio/magnetometer/data rovio/imu/data rovio/thrusters
