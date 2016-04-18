#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)
echo "Controller disconnected"
rosparam set /matlab_controller/enable_thruster1 false
rosparam set /matlab_controller/enable_thruster2 false
rosparam set /matlab_controller/enable_thruster3 false
rosparam set /matlab_controller/enable_thruster4 false
rosparam set /matlab_controller/enable_thruster5 false
rosparam set /matlab_controller/enable_thruster6 false
# reset thursters
echo "Reseting thrusters"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 1 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1525,1500,1500,1500,1500,1500]}"
sleep 1s

# stop thrusters
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 2 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1525,1500,1500,1500,1500]}"
sleep 1s

# stop thrusters
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 3 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1525,1500,1500,1500]}"
sleep 1s
# stop thrusters

rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 4 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1525,1500,1500]}"
sleep 1s
# stop thrusters

rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 5 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1525,1500]}"
sleep 1s
# stop thrusters

rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"
echo "Thruster 6 positive"
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1525]}"
sleep 1s
# stop thrusters
rostopic pub --once /rovio/thrusters std_msgs/UInt16MultiArray "{data:[1500,1500,1500,1500,1500,1500]}"


echo "Controller connected"
rosparam set /matlab_controller/enable_thruster1 true
rosparam set /matlab_controller/enable_thruster2 true
rosparam set /matlab_controller/enable_thruster3 true
rosparam set /matlab_controller/enable_thruster4 true
rosparam set /matlab_controller/enable_thruster5 true
rosparam set /matlab_controller/enable_thruster6 true



