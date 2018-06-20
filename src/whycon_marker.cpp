#include <whycon_lshape/whycon_marker.h>

#include <iostream>

namespace whycon_lshape
{

WhyConMarker::WhyConMarker()
: frozen_(false),
  xyz_(Eigen::Vector3d::Zero()),
  ori_(Eigen::Quaterniond::Identity())
{
}

bool WhyConMarker::frozen() const
{
  return frozen_;
}

const Eigen::Vector3d & WhyConMarker::position() const
{
  return xyz_;
}

const Eigen::Quaterniond & WhyConMarker::orientation() const
{
  return ori_;
}

void WhyConMarker::update(const Eigen::Vector3d & pos, const Eigen::Quaterniond & ori)
{
  frozen_ = (pos - xyz_).lpNorm<Eigen::Infinity>() < 1e-8;
  xyz_ = pos;
  ori_ = ori;
}

}
