#pragma once
#include <ros/ros.h>
#include <geometry_msgs/PoseArray.h>
#include <augmented_whycon/augmented_whycon.h>

namespace augmented_whycon
{

struct AugmentedWhyConROS
{
public:
  AugmentedWhyConROS(ros::NodeHandle & n);

private:
  void on_whycon(const geometry_msgs::PoseArray::ConstPtr & data_msg);
  void publish_results(const std_msgs::Header & header);

private:
  ros::Subscriber WhyCon_sub_;
  ros::Publisher augmentedWhyCon_pub_;
  AugmentedWhyCon augmentedWhyCon_;
};

}
