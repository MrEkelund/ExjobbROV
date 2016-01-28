#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)

roslaunch bluerov workstation.launch
