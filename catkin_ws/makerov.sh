#!/bin/bash

if [ "$#" -gt 0 ];then
    if [ "$1" == "clean" ];then
	echo "git pull & catkin_make clean"
	sshpass -p 'ubuntu' ssh ubuntu@bluerov -t \
	    'export LC_ALL=en_US.UTF-8;source ~/ExjobbROV/catkin_ws/devel/setup.bash; cd ~/ExjobbROV/catkin_ws; git pull; catkin_make clean; catkin_make'
    else
	echo "invalid command"
    fi
else
    echo "git pull & catkin_make"
    sshpass -p 'ubuntu' ssh ubuntu@bluerov -t \
	'export LC_ALL=en_US.UTF-8;source ~/ExjobbROV/catkin_ws/devel/setup.bash; cd ~/ExjobbROV/catkin_ws; git pull; catkin_make'
fi
