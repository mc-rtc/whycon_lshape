#pragma once

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <list>

namespace augmented_whycon{

struct WhyConMarker
{
public:
  WhyConMarker(unsigned int window=500, double alpha=1.);
  WhyConMarker(double timestamp, const Eigen::Vector3d & pos,
    const Eigen::Quaterniond & ori, unsigned int window=500, double alpha=1.);

  void update(double timestamp,
    const Eigen::Vector3d & pos, const Eigen::Quaterniond & ori);
  double distanceFrom(const Eigen::Vector3d & marker);
  const Eigen::Vector3d & position() const;
  const Eigen::Quaterniond & orientation() const;

private:
  Eigen::Vector3d zAxisFilter(const Eigen::Vector3d & marker);

private:
  double timestamp_;
  Eigen::Vector3d xyz_;
  Eigen::Quaterniond ori_;
  Eigen::Vector3d vel_xyz_;
  Eigen::Vector3d dist_xyz_;

  unsigned int window_past_;
  double alpha_;
  std::list<Eigen::Vector3d> past_xyz_;
  std::list<double> past_timestamp_;
};

}
