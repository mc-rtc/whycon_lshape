# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "augmented_whycon: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iaugmented_whycon:/home/pfeiffer/catkin_ws/src/whyconLshape/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(augmented_whycon_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg" NAME_WE)
add_custom_target(_augmented_whycon_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "augmented_whycon" "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg" "geometry_msgs/Point:geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/Pose"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(augmented_whycon
  "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/augmented_whycon
)

### Generating Services

### Generating Module File
_generate_module_cpp(augmented_whycon
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/augmented_whycon
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(augmented_whycon_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(augmented_whycon_generate_messages augmented_whycon_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg" NAME_WE)
add_dependencies(augmented_whycon_generate_messages_cpp _augmented_whycon_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(augmented_whycon_gencpp)
add_dependencies(augmented_whycon_gencpp augmented_whycon_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS augmented_whycon_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(augmented_whycon
  "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/augmented_whycon
)

### Generating Services

### Generating Module File
_generate_module_lisp(augmented_whycon
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/augmented_whycon
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(augmented_whycon_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(augmented_whycon_generate_messages augmented_whycon_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg" NAME_WE)
add_dependencies(augmented_whycon_generate_messages_lisp _augmented_whycon_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(augmented_whycon_genlisp)
add_dependencies(augmented_whycon_genlisp augmented_whycon_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS augmented_whycon_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(augmented_whycon
  "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/augmented_whycon
)

### Generating Services

### Generating Module File
_generate_module_py(augmented_whycon
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/augmented_whycon
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(augmented_whycon_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(augmented_whycon_generate_messages augmented_whycon_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pfeiffer/catkin_ws/src/whyconLshape/msg/AugmentedWhyConMsg.msg" NAME_WE)
add_dependencies(augmented_whycon_generate_messages_py _augmented_whycon_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(augmented_whycon_genpy)
add_dependencies(augmented_whycon_genpy augmented_whycon_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS augmented_whycon_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/augmented_whycon)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/augmented_whycon
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(augmented_whycon_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/augmented_whycon)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/augmented_whycon
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(augmented_whycon_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/augmented_whycon)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/augmented_whycon\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/augmented_whycon
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(augmented_whycon_generate_messages_py geometry_msgs_generate_messages_py)
endif()
