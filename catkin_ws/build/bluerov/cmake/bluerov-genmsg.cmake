# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "bluerov: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ibluerov:/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(bluerov_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg" NAME_WE)
add_custom_target(_bluerov_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "bluerov" "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg" NAME_WE)
add_custom_target(_bluerov_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "bluerov" "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg" "std_msgs/MultiArrayLayout:std_msgs/Header:std_msgs/MultiArrayDimension:std_msgs/UInt16MultiArray"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bluerov
)
_generate_msg_cpp(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/UInt16MultiArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bluerov
)

### Generating Services

### Generating Module File
_generate_module_cpp(bluerov
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bluerov
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(bluerov_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(bluerov_generate_messages bluerov_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_cpp _bluerov_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_cpp _bluerov_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bluerov_gencpp)
add_dependencies(bluerov_gencpp bluerov_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bluerov_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bluerov
)
_generate_msg_lisp(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/UInt16MultiArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bluerov
)

### Generating Services

### Generating Module File
_generate_module_lisp(bluerov
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bluerov
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(bluerov_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(bluerov_generate_messages bluerov_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_lisp _bluerov_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_lisp _bluerov_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bluerov_genlisp)
add_dependencies(bluerov_genlisp bluerov_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bluerov_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov
)
_generate_msg_py(bluerov
  "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/UInt16MultiArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov
)

### Generating Services

### Generating Module File
_generate_module_py(bluerov
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(bluerov_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(bluerov_generate_messages bluerov_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Health.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_py _bluerov_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/erik/Documents/exjobb/catkin_ws/src/bluerov/msg/Thruster.msg" NAME_WE)
add_dependencies(bluerov_generate_messages_py _bluerov_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bluerov_genpy)
add_dependencies(bluerov_genpy bluerov_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bluerov_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bluerov)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bluerov
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(bluerov_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bluerov)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bluerov
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(bluerov_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bluerov
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(bluerov_generate_messages_py std_msgs_generate_messages_py)
