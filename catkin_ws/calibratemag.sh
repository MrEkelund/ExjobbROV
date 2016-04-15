#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)
rostopic pub --once /sensor_fusion/calibrate_mag std_msgs/Bool true
