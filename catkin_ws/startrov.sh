#!/bin/bash
sshpass -p 'ubuntu' ssh ubuntu@bluerov -t 'export LC_ALL=en_US.UTF-8;export ROS_MASTER_URI=http://10.0.0.20:11311; export ROS_IP=10.0.0.20; source ~/ExjobbROV/catkin_ws/devel/setup.bash; roslaunch bluerov rov_core.launch'
