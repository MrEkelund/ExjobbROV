cmake_minimum_required(VERSION 2.8.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${ROS_LIB_DIR} includes)

# Remove this if using an Arduino without native USB (eg, other than Leonardo)
add_definitions(-DUSB_CON)

file(GLOB AVR_ROS_SRC "avr_ros/*.cpp")

#file(GLOB ROS_DIR_CPP "${ROS_LIB_DIR}/*.cpp")

#file(GLOB OWN_CPP "includes/*.cpp")
set(ROS_DIR_CPP
  ${ROS_LIB_DIR}/time.cpp
)

set(OWN_CPP
  includes/ROVServo.cpp
  includes/ROVIO.cpp
  includes/MS5837.cpp
  includes/MPU6000.cpp
  includes/MS5611.cpp
  includes/MS5837.cpp
  includes/HMC5883L.cpp
  includes/vector3.cpp
  includes/AP_Math.cpp
  includes/matrix_alg.cpp
)

set(PROJECT_SRC
#    ${AVR_ROS_SRC}
#    ${ARDUINO_SOURCE_FILES}
    ${ROS_DIR_CPP}
    ${OWN_CPP}
)

generate_arduino_firmware(hello
  SRCS ard.cpp ${PROJECT_SRC}
  BOARD mega2560
  PORT /dev/ttyACM0
)
