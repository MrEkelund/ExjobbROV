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
#  Sensors.msg
#  States.msg 
)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS
  message_runtime std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)




## Specify additional locations of header files
