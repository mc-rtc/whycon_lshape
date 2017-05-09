#pragma once
#include <ros/ros.h>
#include <augmented_whycon/AugmentedWhyConMsg.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/transform_broadcaster.h>

namespace augmented_whycon
{

struct AugmentedWhyConROSRviz
{
public:
  AugmentedWhyConROSRviz(ros::NodeHandle & n);

private:
  void init(const AugmentedWhyConMsg::ConstPtr & data_msg);
  void on_whycon_augmented(const AugmentedWhyConMsg::ConstPtr & data_msg);
  void parsePositions(const AugmentedWhyConMsg::ConstPtr & data_msg);
  void parseOrientations(const AugmentedWhyConMsg::ConstPtr & data_msg);
  void publish_results(const AugmentedWhyConMsg::ConstPtr & data_msg);

private:
  ros::Subscriber augmentedWhyCon_sub_;
  ros::Publisher markers_pub_;
  visualization_msgs::MarkerArray markers_;
  visualization_msgs::Marker shadow_point_;
  visualization_msgs::Marker shadow_line_;
  std::vector<tf::Transform> tf_vector_;
};

}
