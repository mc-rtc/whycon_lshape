#pragma once
#include <ros/ros.h>
#include <geometry_msgs/PoseArray.h>
#include <whycon_lshape/whycon_lshape.h>

namespace whycon_lshape
{

struct WhyConLShapeROS
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
  WhyConLShapeROS(ros::NodeHandle & n);

private:
  void on_whycon(const geometry_msgs::PoseArray::ConstPtr & data_msg);
  void publish_results(const std_msgs::Header & header);

private:
  ros::Subscriber sub_;
  ros::Publisher pub_;
  WhyConLShape lshape_;
};

}
