#!/bin/bash

if [ "$#" -gt 0 ];then
    if [ "$1" == "clean" ];then
	echo "scp & catkin_make clean"
  sshpass -p 'ubuntu' scp -r src ubuntu@bluerov:ExjobbROV/catkin_ws
	sshpass -p 'ubuntu' ssh ubuntu@bluerov -t \
	    'export LC_ALL=en_US.UTF-8;source ~/ExjobbROV/catkin_ws/devel/setup.bash; cd ~/ExjobbROV/catkin_ws; catkin_make clean; catkin_make'
    else
	echo "invalid command"
    fi
else
    echo "scp pull & catkin_make"
    sshpass -p 'ubuntu' scp -r src ubuntu@bluerov:ExjobbROV/catkin_ws
    sshpass -p 'ubuntu' ssh ubuntu@bluerov -t \
	'export LC_ALL=en_US.UTF-8;source ~/ExjobbROV/catkin_ws/devel/setup.bash; cd ~/ExjobbROV/catkin_ws; catkin_make'
fi
