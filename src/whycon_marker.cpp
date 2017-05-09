#include <augmented_whycon/whycon_marker.h>

#include <iostream>

namespace augmented_whycon{

WhyConMarker::WhyConMarker(unsigned int window, double alpha)
{
  timestamp_ = 0.;

  xyz_ = Eigen::Vector3d::Zero();
  vel_xyz_ = Eigen::Vector3d::Zero();
  dist_xyz_ = Eigen::Vector3d::Zero();

  window_past_ = window;
  alpha_ = alpha;
}

WhyConMarker::WhyConMarker(double timestamp, const Eigen::Vector3d & pos,
  const Eigen::Quaterniond & ori, unsigned int window, double alpha)
  : WhyConMarker(window, alpha)
{
  timestamp = timestamp;
  xyz_ = pos;
  ori_ = ori;
}

const Eigen::Vector3d & WhyConMarker::position() const
{
  return xyz_;
}

const Eigen::Quaterniond & WhyConMarker::orientation() const
{
  return ori_;
}

void WhyConMarker::update(double timestamp, const Eigen::Vector3d & pos,
  const Eigen::Quaterniond & ori)
{
  if (timestamp_ == 0.)
  {
    timestamp_ = timestamp;
    xyz_ = pos;
    ori_ = ori;
    past_xyz_.push_back(xyz_);
    past_timestamp_.push_back(timestamp_);
  }
  else
  {
    Eigen::Vector3d filtered_pos = zAxisFilter(pos);
    Eigen::Vector3d dist_xyz = filtered_pos - xyz_;
    double dt = timestamp - timestamp_;
    vel_xyz_ = dist_xyz / dt;
    dist_xyz_ += dist_xyz.cwiseAbs();

    timestamp_ = timestamp;
    xyz_ = filtered_pos;
    ori_ = ori;
  }
  past_xyz_.push_back(pos);
  past_timestamp_.push_back(timestamp_);
  if (past_timestamp_.size() > window_past_)
  {
    past_timestamp_.pop_front();
    past_xyz_.pop_front();
  }
}

double WhyConMarker::distanceFrom(const Eigen::Vector3d & pos)
{
  Eigen::Vector3d filtered_pos = pos;
  if (past_timestamp_.size() > 0.)
  {
    filtered_pos = zAxisFilter(pos);
  }
  return (filtered_pos - xyz_).norm();
}

Eigen::Vector3d WhyConMarker::zAxisFilter(const Eigen::Vector3d & pos)
{
  Eigen::Vector3d filtered_pos = pos;
  if (past_timestamp_.size() > 2.)
  {
    double RC = 1.0 / (0.0005 * 2 * 3.14);
    std::list<double>::iterator it = past_timestamp_.end();
    std::advance(it, -2);
    double dt = 1.0 / (past_timestamp_.back()- *it);
    double alpha = dt / (RC + dt);
    double z_filter = past_xyz_.front()[2];
    for(const Eigen::Vector3d & xyz: past_xyz_)
    {
      z_filter = z_filter + (alpha * (xyz[2] - z_filter));
    }
    filtered_pos[2] = z_filter;
  }
  return filtered_pos;
}











}
