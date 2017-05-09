cmake_minimum_required(VERSION 2.8.3)
project(augmented_whycon)

# set some flags
add_definitions(-std=c++11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O4 -march=native -Wfatal-errors")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O0 -g -Wfatal-errors")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake-configs")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  std_msgs
  message_generation
  tf
)

add_message_files(
  FILES
  AugmentedWhyConMsg.msg
)

generate_messages(
  DEPENDENCIES geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp geometry_msgs std_msgs message_runtime tf
)

include_directories(
  ${catkin_INCLUDE_DIRS} include
)

add_library(augmented_whycon SHARED src/augmented_whycon.cpp src/whycon_marker.cpp src/mc_torquing_controller_bwFilter.cpp)

add_executable(augmented_whycon-node src/ros/main.cpp src/ros/augmented_whycon_ros.cpp)
set_target_properties(augmented_whycon-node PROPERTIES OUTPUT_NAME augmented_whycon)
add_dependencies(augmented_whycon-node augmented_whycon_generate_messages_cpp)
target_link_libraries(augmented_whycon-node ${catkin_LIBRARIES} augmented_whycon)

add_executable(augmented_whycon_rviz-node src/ros/main_rviz.cpp src/ros/augmented_whycon_ros_rviz.cpp)
set_target_properties(augmented_whycon_rviz-node PROPERTIES OUTPUT_NAME augmented_whycon_rviz)
add_dependencies(augmented_whycon_rviz-node augmented_whycon_generate_messages_cpp)
target_link_libraries(augmented_whycon_rviz-node ${catkin_LIBRARIES} augmented_whycon)

install(DIRECTORY include/${PACKAGE_NAME}
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
## Mark executables and/or libraries for installation
install(TARGETS augmented_whycon augmented_whycon-node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)