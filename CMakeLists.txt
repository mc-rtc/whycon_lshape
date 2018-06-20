cmake_minimum_required(VERSION 2.8.3)
project(whycon_lshape)

# set some flags
add_definitions(-std=c++0x)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O4 -march=native -Wfatal-errors")
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
  LShapeMsg.msg
  WhyConLShapeMsg.msg
)

generate_messages(
  DEPENDENCIES geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp geometry_msgs std_msgs message_runtime tf
)

find_package(Eigen3 REQUIRED)

include_directories(
  ${catkin_INCLUDE_DIRS} include ${EIGEN3_INCLUDE_DIRS}
)

add_library(whycon_lshape SHARED src/whycon_lshape.cpp src/whycon_marker.cpp src/MAFilter.cpp)

add_executable(whycon_lshape-node src/ros/main.cpp src/ros/whycon_lshape_ros.cpp)
set_target_properties(whycon_lshape-node PROPERTIES OUTPUT_NAME whycon_lshape)
add_dependencies(whycon_lshape-node whycon_lshape_generate_messages_cpp)
target_link_libraries(whycon_lshape-node ${catkin_LIBRARIES} whycon_lshape)

install(DIRECTORY include/${PACKAGE_NAME}
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
## Mark executables and/or libraries for installation
install(TARGETS whycon_lshape whycon_lshape-node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
