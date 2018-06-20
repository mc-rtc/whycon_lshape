#pragma once

#include <whycon_lshape/whycon_marker.h>
#include <whycon_lshape/BWFilter.h>
#include <Eigen/Geometry>
#include <array>
#include <queue>
#include <utility>

namespace whycon_lshape
{

struct WhyConLShape
{
public:
  WhyConLShape();

  unsigned int WhyConMarkersNr();
  unsigned int LShapesNr();

  const WhyConMarker & iWhyConMarker(unsigned int i);
  // std::pair<const std::array<unsigned int, 3> &, const Eigen::Quaterniond &> iLShape(unsigned int i);

  std::tuple<int, std::vector<int>, Eigen::Vector2i, std::vector<int>, std::vector<Eigen::Vector3d>, std::vector<Eigen::Quaterniond> > LShapeDetector();

  void update(double timestamp, const std::list<Eigen::Vector3d> & markers_position,
    const std::list<Eigen::Quaterniond> & markers_orientation);

private:
  void idxsDetection(double timestamp, const std::list<Eigen::Vector3d> & markers,
    const std::list<Eigen::Quaterniond> & markers_orientation);
  void LShapesDetection();

private:
  std::vector<WhyConMarker> WhyConMarkers_;
  unsigned int nrMarkersWhycon;
  int detectedLShapes;
  std::vector<int> idx;
  Eigen::Vector2i ToolWallIdx;
  std::vector<int> LShapesIdxs;
  Eigen::MatrixXd MarkersPositionPrev;
  Eigen::VectorXi frozen;
  std::vector<Eigen::Vector3d> LShapesPosition;
  std::vector<Eigen::Quaterniond> LShapesOrientation;
  bool markersInitialized[4] = {false, false, false, false};
  int nrLShapes = 4;
  double wingLengthLShapeRail = 0.08;
  double wingLengthLShapeTool = 0.04;
  double wingLengthLShapeWall_0 = 0.05;
  double wingLengthLShapeWall_1 = 0.06;
  double wingLengthLShapeTolerance = 0.005;
  BWFilter * bwFiltRailU;
  BWFilter * bwFiltRailV;
  BWFilter * bwFiltToolU;
  BWFilter * bwFiltToolV;
  BWFilter * bwFiltWallU;
  BWFilter * bwFiltWallV;
  BWFilter * bwFiltWallInclU;
  BWFilter * bwFiltWallInclV;
  int cntrRun = 0;
};

} // namespace whycon_lshape
