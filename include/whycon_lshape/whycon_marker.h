#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <list>

namespace whycon_lshape
{

struct WhyConMarker
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
  WhyConMarker();
  void update(const Eigen::Vector3d & pos, const Eigen::Quaterniond & ori);
  double distanceFrom(const Eigen::Vector3d & marker);
  bool frozen() const;
  const Eigen::Vector3d & position() const;
  const Eigen::Quaterniond & orientation() const;

private:
  bool frozen_;
  Eigen::Vector3d xyz_;
  Eigen::Quaterniond ori_;
};

} // namespace whycon_lshape
