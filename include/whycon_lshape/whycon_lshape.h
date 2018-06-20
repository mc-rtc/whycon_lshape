#pragma once

#include <whycon_lshape/whycon_marker.h>
#include <whycon_lshape/MAFilter.h>
#include <Eigen/Geometry>
#include <Eigen/StdVector>
#include <array>
#include <queue>
#include <utility>

namespace whycon_lshape
{

/** An L shape formed by three WhyCon marker */
struct LShape
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  LShape(const std::string & name, double wl)
  : name(name), wing_length(wl),
    filter_x(25), filter_y(25)
  {
  }

  /** Name used to identify the shape */
  std::string name;
  /** Lenght of the wings */
  double wing_length;
  /** True if the shape has been found among the current markers */
  bool found = false;
  /** Indices of the markers that compose the shape
   *
   * The first marker is the origin.
   * The second marker points towards the x direction
   * The third marker points towards the y direction
   *
   * The values have no sense if found is false
   */
  std::array<size_t, 3> markers;
  /** Filter for the x-direction */
  MAFilter filter_x;
  /** Filter for the y-direction */
  MAFilter filter_y;
  /** Position of the L center */
  Eigen::Vector3d pos;
  /** Orientation of the L */
  Eigen::Quaterniond ori;
};

struct WhyConLShape
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
  WhyConLShape();

  /** Add an l-shape */
  void add_lshape(const std::string & name, double wl);

  /** Update a single marker */
  void update(size_t idx, const Eigen::Vector3d & pos, const Eigen::Quaterniond & ori);

  /** Set tolerance */
  void tolerance(double t) { tolerance_ = t; }
  /** Get tolerance */
  double tolerance() { return tolerance_; }

  const std::vector<LShape> & detect();
private:
  void LShapesDetection();
private:
  std::vector<WhyConMarker, Eigen::aligned_allocator<WhyConMarker>> markers_;
  std::vector<LShape> shapes_;
  double tolerance_ = 0.005;
  int iter_ = 0;
};

} // namespace whycon_lshape
