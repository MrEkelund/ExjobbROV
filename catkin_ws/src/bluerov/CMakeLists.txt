cmake_minimum_required(VERSION 2.8.3)
project(bluerov)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
  joy
  message_generation
  dynamic_reconfigure
)

## Declare ROS messages and services
##add_message_files(FILES
##
##)


## Generate added messages and services
##generate_messages(DEPENDENCIES
##  std_msgs
##)

## Add dynamic reconfigure api
generate_dynamic_reconfigure_options(
  config/teleop_xbox.config
)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS
  message_runtime
)

## Specify additional locations of header files
include_directories(include ${catkin_INCLUDE_DIRS} ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake)

add_executable(teleop_xbox src/teleop_xbox.cpp)
target_link_libraries(teleop_xbox ${catkin_LIBRARIES})
add_dependencies(teleop_xbox ${catkin_EXPORTED_TARGETS})

add_executable(matlab_controller src/matlab_controller.cpp)
target_link_libraries(matlab_controller ${catkin_LIBRARIES})
add_dependencies(matlab_controller ${catkin_EXPORTED_TARGETS})

add_executable(heartbeat_rovio src/heartbeat_rovio.cpp)
target_link_libraries(heartbeat_rovio ${catkin_LIBRARIES})
add_dependencies(heartbeat_rovio ${catkin_EXPORTED_TARGETS})
