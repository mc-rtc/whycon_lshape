#include "whycon_lshape_ros.h"
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <functional>
#include <whycon_lshape/WhyConLShapeMsg.h>
#include <geometry_msgs/Pose.h>
#include <sstream>
#include <ros/console.h>

#include <ctime>
#include <iostream>

namespace whycon_lshape
{

WhyConLShapeROS::WhyConLShapeROS(ros::NodeHandle & n)
{
  sub_ = n.subscribe("/whycon/poses", 1000., &WhyConLShapeROS::on_whycon, this);
  pub_ =
    n.advertise<whycon_lshape::WhyConLShapeMsg>("whycon_lshape", 1);
}

void WhyConLShapeROS::on_whycon(const geometry_msgs::PoseArray::ConstPtr & data_msg)
{
  std::list<Eigen::Vector3d> markers_position;
  std::list<Eigen::Quaterniond> markers_orientation;
  for (const geometry_msgs::Pose & pose: data_msg->poses)
  {
    markers_position.push_back(Eigen::Vector3d(pose.position.x, pose.position.y, pose.position.z));
    //Eigen::Quaterniond a = Eigen::Quaterniond(pose.orientation.w, pose.orientation.x, pose.orientation.y, pose.orientation.z);
    //markers_orientation.push_back(a);
  }
  double timestamp = data_msg->header.stamp.toSec();
  lshape_.update(timestamp, markers_position, markers_orientation);
  publish_results(data_msg->header);
}

void WhyConLShapeROS::publish_results(const std_msgs::Header & header)
{
  // due to limited geometry_msgs options unsafe data types
  whycon_lshape::WhyConLShapeMsg msg;
  msg.header = header;
  for (unsigned int i = 0; i < lshape_.WhyConMarkersNr(); ++i)
  {
    const Eigen::Vector3d & pos = lshape_.iWhyConMarker(i).position();
    geometry_msgs::Point point;
    point.x = pos[0];
    point.y = pos[1];
    point.z = pos[2];
    const Eigen::Quaterniond & ori = lshape_.iWhyConMarker(i).orientation();
    geometry_msgs::Quaternion quaternion;
    quaternion.x = ori.x();
    quaternion.y = ori.y();
    quaternion.z = ori.z();
    quaternion.w = ori.w();
    geometry_msgs::Pose pose;
    pose.position = point;
    msg.poses.push_back(pose);
  }

  auto LShapes = lshape_.LShapeDetector();

  msg.nrDetectedLShapes = std::get<0>(LShapes);

  for (int i=0;i<std::get<0>(LShapes);i++)
  {
    geometry_msgs::Point idx;
    idx.x = std::get<1>(LShapes)[i*3+0];
    idx.y = std::get<1>(LShapes)[i*3+1];
    idx.z = std::get<1>(LShapes)[i*3+2];
    msg.idx.push_back(idx);
  }

  for (int i=0;i<std::get<0>(LShapes);i++){
    msg.LShapesIdxs.push_back(std::get<3>(LShapes)[i]);
  }

  for (int i=0;i<std::get<0>(LShapes);i++){
    geometry_msgs::Point LShapesPos;
    LShapesPos.x = std::get<4>(LShapes)[i][0];
    LShapesPos.y = std::get<4>(LShapes)[i][1];
    LShapesPos.z = std::get<4>(LShapes)[i][2];
    msg.LShapesPos.push_back(LShapesPos);
  }

  for (int i=0;i<std::get<0>(LShapes);i++){
    geometry_msgs::Quaternion quat;
    quat.w = std::get<5>(LShapes)[i].w();
    quat.x = std::get<5>(LShapes)[i].x();
    quat.y = std::get<5>(LShapes)[i].y();
    quat.z = std::get<5>(LShapes)[i].z();
    msg.LShapesOri.push_back(quat);
  }
  pub_.publish(msg);
}

}
