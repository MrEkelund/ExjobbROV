#!/bin/bash
rostopic pub --once /sensor_fusion/calibrate_mag std_msgs/Bool true
