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
  double tolerance = lshape_.tolerance();
  n.param("tolerance", tolerance, tolerance);
  lshape_.tolerance(tolerance);
  XmlRpc::XmlRpcValue v;
  n.param("l_shapes", v, v);
  if(v.valid())
  {
    for(int i = 0; i < v.size(); ++i)
    {
      auto & vv = v[i];
      if(vv.hasMember("name") && vv.hasMember("wing_length"))
      {
        std::string name = vv["name"];
        double wl = vv["wing_length"];
        lshape_.add_lshape(name, wl);
        ROS_INFO_STREAM("Added L-shape " << name << " (wing length: " << wl << ")");
      }
      else
      {
        ROS_ERROR_STREAM("Invalid entry in l_shapes param");
      }
    }
  }
}

void WhyConLShapeROS::on_whycon(const geometry_msgs::PoseArray::ConstPtr & data_msg)
{
  size_t idx = 0;
  for(const auto & pose : data_msg->poses)
  {
    lshape_.update(idx, {pose.position.x, pose.position.y, pose.position.z},
                   {pose.orientation.w, pose.position.x, pose.orientation.y, pose.orientation.z});
    idx++;
  }
  publish_results(data_msg->header);
}

void WhyConLShapeROS::publish_results(const std_msgs::Header & header)
{
  // due to limited geometry_msgs options unsafe data types
  whycon_lshape::WhyConLShapeMsg msg;
  msg.header = header;
  const auto & lshapes = lshape_.detect();
  for(const auto & s : lshapes)
  {
    if(!s.found) { continue; }
    whycon_lshape::LShapeMsg lmsg;
    lmsg.name = s.name;
    lmsg.pose.position.x = s.pos.x();
    lmsg.pose.position.y = s.pos.y();
    lmsg.pose.position.z = s.pos.z();
    lmsg.pose.orientation.w = s.ori.w();
    lmsg.pose.orientation.x = s.ori.x();
    lmsg.pose.orientation.y = s.ori.y();
    lmsg.pose.orientation.z = s.ori.z();
    msg.shapes.push_back(lmsg);
  }
  pub_.publish(msg);
}

}
