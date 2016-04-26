#!/bin/bash
export ROS_MASTER_URI=http://bluerov:11311
export ROS_IP=$(gethostip -d workstation)

trap ctrl_c INT

function ctrl_c() {
  echo "Abort"
  exit
}

if [[ $# > 0 ]]; then
  if [[ $# == 4 ]]; then
    testnum="$1"
    maxscale="$2"
    minscale="$3"
    name="$4"
    echo $testnum $maxscale $minscale $name
  else
    echo "Usage: ./test.sh testnum maxscaling minscaling logname"
    exit
  fi
else
  echo -e "Choose test\n [1]: All DOF test.\n [2]: Yaw test.\n [3]: RollPitch test."
  read testnum

  echo -e "Set max scaling of the test signal in the interval [0-1]"
  read maxscale

  echo -e "Set min scaling of the test signal in the interval [0-1]"
  read minscale

  echo -e "Enter the name you want for the logfile"
  read name
fi

case $testnum in
  1)  echo "All DOF test"
  thrusters=(1 2 3 4 5 6)
  ;;
  2)  echo "Yaw test"
  thrusters=(3 4)
  ;;
  3)  echo  "RollPitch test"
  thrusters=(1 2 5 6)
  ;;
  *) echo "Invalid test"
  exit
  ;;
esac


awk -v maxs=$maxscale -v mins=$minscale -v n2=1 -v n3=0 \
'BEGIN {if (maxs<=n2 && maxs>=n3 && mins<=n2 && mins>=n3);
else {
  printf ("Invalid scale\n")
  exit 1}}'

if [[ ${?} -eq 1 ]]; then
  exit
fi

for i in 1 2 3 4 5 6
do
  rosparam set /matlab_controller/enable_thruster${i} false
done

rosparam set /matlab_controller/test 0

for i in "${thrusters[@]}"
do
  rosparam set /matlab_controller/enable_thruster${i} true
  rosparam set /matlab_controller/max_scale${i} $maxscale
  rosparam set /matlab_controller/min_scale${i} $minscale
done

cd ../simulink/Estimation/bag
rosbag record -o $name sensor_fusion/states rovio/water_pressure/data rovio/magnetometer/data rovio/imu/data rovio/thrusters
