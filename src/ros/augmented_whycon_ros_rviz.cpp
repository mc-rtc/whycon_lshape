#include "augmented_whycon_ros_rviz.h"
#include <eigen3/Eigen/Core>
#include <functional>

#include <string>
#include <ctime>
#include <iostream>
#include <random>

namespace augmented_whycon
{
AugmentedWhyConROSRviz::AugmentedWhyConROSRviz(ros::NodeHandle & n)
{
  // augmentedWhyCon_sub_ = n.subscribe("/augmented_whycon/augmented_whycon", 1000.,
  //   &AugmentedWhyConROSRviz::on_whycon_augmented, this);
  // markers_pub_ =
  //   n.advertise<visualization_msgs::MarkerArray>("augmented_whycon", 1);

  // shadow_point_.header.frame_id = "/camera_rgb_optical_frame";
  // shadow_point_.id = 0;
  // shadow_point_.ns = "points";
  // shadow_point_.action = visualization_msgs::Marker::ADD;
  // shadow_point_.pose.orientation.w = 1.;
  // shadow_point_.type = visualization_msgs::Marker::CYLINDER;
  // shadow_point_.scale.x = 0.05;
  // shadow_point_.scale.y = 0.05;
  // shadow_point_.scale.z = 0.001;

  // shadow_line_.header.frame_id = "/camera_rgb_optical_frame";
  // shadow_line_.id = 0;
  // shadow_line_.ns = "lines";
  // shadow_line_.action = visualization_msgs::Marker::ADD;
  // shadow_line_.pose.orientation.w = 1.;
  // shadow_line_.type = visualization_msgs::Marker::LINE_STRIP;
  // shadow_line_.scale.x = 0.001;
}

void AugmentedWhyConROSRviz::on_whycon_augmented(
    const AugmentedWhyConMsg::ConstPtr & data_msg)
{
  init(data_msg);
  parsePositions(data_msg);
  parseOrientations(data_msg);
  publish_results(data_msg);
}

void AugmentedWhyConROSRviz::init(const AugmentedWhyConMsg::ConstPtr & data_msg)
{
  // if (markers_.markers.empty())
  // {
  //   std::random_device rd;
  //   std::mt19937 gen(rd());
  //   std::uniform_real_distribution<> dis(0, 1);
  //   markers_.markers.resize(2 * data_msg->poses.size());
  //   for(unsigned int i = 0; i < data_msg->poses.size(); ++i)
  //   {
  //     float r = dis(gen);
  //     float g = dis(gen);
  //     float b = dis(gen);
  //     visualization_msgs::Marker marker = shadow_point_;
  //     marker.id = i;
  //     marker.color.r = r;
  //     marker.color.g = g;
  //     marker.color.b = b;
  //     marker.color.a = 1.0;
  //     markers_.markers[i] = marker;
  //     marker = shadow_line_;
  //     marker.id = data_msg->poses.size() + i;
  //     marker.color.r = r;
  //     marker.color.g = g;
  //     marker.color.b = b;
  //     marker.color.a = 1.0;
  //     markers_.markers[data_msg->poses.size() + i] = marker;
  //   }
  // }
  // else
  // {
  //   tf_vector_.clear();
  //   for (unsigned int i = data_msg->poses.size() * 2; i < markers_.markers.size(); ++i)
  //   {
  //     markers_.markers[i].action = visualization_msgs::Marker::DELETE;
  //   }
  //   markers_pub_.publish(markers_);
  //   markers_.markers.resize(data_msg->poses.size() * 2);
  // }
}

void AugmentedWhyConROSRviz::parsePositions(const AugmentedWhyConMsg::ConstPtr & data_msg)
{
  // for (unsigned int i = 0; i < data_msg->poses.size(); ++i)
  // {
  //   geometry_msgs::Pose pose = data_msg->poses[i];
  //   markers_.markers[i].pose = pose;
  //   markers_.markers[data_msg->poses.size() + i].points.push_back(pose.position);
  //   tf::Transform tf;
  //   tf.setOrigin(tf::Vector3(pose.position.x, pose.position.y, pose.position.z));
  //   tf::Quaternion q(pose.orientation.x,
  //     pose.orientation.y, pose.orientation.z, pose.orientation.w);
  //   tf.setRotation(q);
  //   tf_vector_.push_back(tf);
  // }
}

void AugmentedWhyConROSRviz::parseOrientations(const AugmentedWhyConMsg::ConstPtr & data_msg)
{
  // for (unsigned int i = 0; i < data_msg->LShapesOri.size(); ++i)
  // {
  //   geometry_msgs::Point idxs = data_msg->LShapesIdxs[i];
  //   visualization_msgs::Marker short_line = shadow_line_;
  //   short_line.id = data_msg->poses.size() * 2 + i * 3 + 1;
  //   short_line.ns = "ori_lines";
  //   short_line.color.r = 0.9;
  //   short_line.color.g = 0.1;
  //   short_line.color.b = 0.2;
  //   short_line.color.a = 0.5;
  //   short_line.scale.x = 0.005;
  //   short_line.scale.y = 0.005;
  //   short_line.scale.z = 0.005;
  //   short_line.points.push_back(markers_.markers[idxs.y].pose.position);
  //   short_line.points.push_back(markers_.markers[idxs.x].pose.position);
  //   markers_.markers.push_back(short_line);

  //   visualization_msgs::Marker tall_line = shadow_line_;
  //   tall_line.id = data_msg->poses.size() * 2 + i * 3 + 2;
  //   tall_line.ns = "ori_lines";
  //   tall_line.color.r = 0.2;
  //   tall_line.color.g = 0.9;
  //   tall_line.color.b = 0.1;
  //   tall_line.color.a = 0.5;
  //   tall_line.scale.x = 0.005;
  //   tall_line.scale.y = 0.005;
  //   tall_line.scale.z = 0.005;
  //   tall_line.points.push_back(markers_.markers[idxs.y].pose.position);
  //   tall_line.points.push_back(markers_.markers[idxs.z].pose.position);
  //   markers_.markers.push_back(tall_line);

  //   geometry_msgs::Quaternion quat = data_msg->LShapesOri[i];
  //   tf::Transform tf;
  //   geometry_msgs::Point origin = markers_.markers[idxs.y].pose.position;
  //   tf.setOrigin(tf::Vector3(origin.x, origin.y, origin.z));
  //   tf::Quaternion q(quat.x, quat.y, quat.z, quat.w);
  //   tf.setRotation(q);
  //   tf_vector_.push_back(tf);
  // }
}

void AugmentedWhyConROSRviz::publish_results(const AugmentedWhyConMsg::ConstPtr & data_msg)
{
  // markers_pub_.publish(markers_);
  // static tf::TransformBroadcaster br;
  // for (unsigned int i = 0; i < tf_vector_.size(); ++i)
  // {
  //   br.sendTransform(tf::StampedTransform(tf_vector_[i], ros::Time::now(),
  //     "/camera_rgb_optical_frame", std::to_string(i)));
  // }
}

}
