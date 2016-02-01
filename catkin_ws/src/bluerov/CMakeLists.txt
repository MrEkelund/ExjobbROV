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
  mavros
  message_generation
  dynamic_reconfigure
)

## Declare ROS messages and services
add_message_files(FILES
  Thruster.msg
  Health.msg
)

## Generate added messages and services
generate_messages(DEPENDENCIES
  std_msgs
)

## Add dynamic reconfigure api
generate_dynamic_reconfigure_options(
  config/teleop_xbox.config
  config/matlab_controller.config
  ##config/pid_parameters.config
)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS
  message_runtime
)

## Specify additional locations of header files
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(controller src/controller.cpp)
target_link_libraries(controller ${catkin_LIBRARIES})
add_dependencies(controller ${catkin_EXPORTED_TARGETS})

add_executable(teleop_xbox src/teleop_xbox.cpp)
target_link_libraries(teleop_xbox ${catkin_LIBRARIES})
add_dependencies(teleop_xbox ${catkin_EXPORTED_TARGETS})

add_executable(matlab_controller src/matlab_controller.cpp)
target_link_libraries(matlab_controller ${catkin_LIBRARIES})
add_dependencies(matlab_controller ${catkin_EXPORTED_TARGETS})
