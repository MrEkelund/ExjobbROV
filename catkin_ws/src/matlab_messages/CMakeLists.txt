cmake_minimum_required(VERSION 2.8.3)
project(matlab_messages)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Declare ROS messages and services
add_message_files(FILES
  States.msg
  Sensors.msg
)

## Generate added messages and services
generate_messages(DEPENDENCIES
  std_msgs
)


## Declare a catkin package
catkin_package(CATKIN_DEPENDS
  message_runtime
)

## Specify additional locations of header files
