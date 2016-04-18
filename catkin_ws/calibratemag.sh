#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)
rostopic pub -1 /sensor_fusion/calibrate_mag std_msgs/Bool true
rostopic pub -1 /sensor_fusion/restart std_msgs/Bool True
