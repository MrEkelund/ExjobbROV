cmake_minimum_required(VERSION 2.8.3)

include_directories(${ROS_LIB_DIR} includes)

# Remove this if using an Arduino without native USB (eg, other than Leonardo)
add_definitions(-DUSB_CON)

generate_arduino_firmware(hello
  SRCS ard.cpp ${ROS_LIB_DIR}/time.cpp includes/ROVServo.cpp
  BOARD mega2560
  PORT /dev/ttyACM0
)
