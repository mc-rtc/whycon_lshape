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

struct WhyConLShape
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
  WhyConLShape();

  unsigned int WhyConMarkersNr();
  unsigned int LShapesNr();

  const WhyConMarker & iWhyConMarker(unsigned int i);
  // std::pair<const std::array<unsigned int, 3> &, const Eigen::Quaterniond &> iLShape(unsigned int i);

  struct Result
  {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    int detectedLShapes;
    std::vector<int> idx;
    std::vector<int> LShapesIdxs;
    std::vector<Eigen::Vector3d> LShapesPosition;
    std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond>> LShapesOrientation;
  };

  Result LShapeDetector();

  void update(double timestamp, const std::list<Eigen::Vector3d> & markers_position,
    const std::list<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond>> & markers_orientation);

private:
  void idxsDetection(double timestamp, const std::list<Eigen::Vector3d> & markers,
    const std::list<Eigen::Quaterniond> & markers_orientation);
  void LShapesDetection();

private:
  std::vector<WhyConMarker, Eigen::aligned_allocator<WhyConMarker>> WhyConMarkers_;
  unsigned int nrMarkersWhycon;
  int detectedLShapes;
  std::vector<int> idx;
  std::vector<int> LShapesIdxs;
  Eigen::MatrixXd MarkersPositionPrev;
  Eigen::VectorXi frozen;
  std::vector<Eigen::Vector3d> LShapesPosition;
  std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond>> LShapesOrientation;
  bool markersInitialized[4] = {false, false, false, false};
  int nrLShapes = 4;
  double wingLengthLShapeRail = 0.08;
  double wingLengthLShapeTool = 0.04;
  double wingLengthLShapeWall_0 = 0.05;
  double wingLengthLShapeWall_1 = 0.06;
  double wingLengthLShapeTolerance = 0.005;
  MAFilter maFiltRailU;
  MAFilter maFiltRailV;
  MAFilter maFiltToolU;
  MAFilter maFiltToolV;
  MAFilter maFiltWallU;
  MAFilter maFiltWallV;
  MAFilter maFiltWallInclU;
  MAFilter maFiltWallInclV;
  int cntrRun = 0;
};

} // namespace whycon_lshape
