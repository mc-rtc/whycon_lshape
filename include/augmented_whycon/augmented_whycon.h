#pragma once

#include <augmented_whycon/whycon_marker.h>
#include <augmented_whycon/mc_torquing_controller_bwFilter.h>
#include <Eigen/Geometry>
#include <array>

namespace augmented_whycon{

struct AugmentedWhyCon
{
public:
  AugmentedWhyCon();

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
  int detectedLShapes;
  std::vector<int> idx;
  Eigen::Vector2i ToolWallIdx;
  std::vector<int> LShapesIdxs;
  std::vector<Eigen::Vector3d> LShapesPosition;
  std::vector<Eigen::Quaterniond> LShapesOrientation;
  bool markersInitialized[4] = {false, false, false, false};
  int nrLShapes = 4;
  double wingLengthLShapeRail = 0.08;
  double wingLengthLShapeTool = 0.05;
  double wingLengthLShapeWall_0 = 0.06;
  double wingLengthLShapeWall_1 = 0.07;
  double wingLengthLShapeTolerance = 0.005;
  bwFilter * bwFiltRailU;
  bwFilter * bwFiltRailV;
  bwFilter * bwFiltToolU;
  bwFilter * bwFiltToolV;
  bwFilter * bwFiltWallU;
  bwFilter * bwFiltWallV;
  bwFilter * bwFiltWallInclU;
  bwFilter * bwFiltWallInclV;
};

}
