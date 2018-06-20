#include <whycon_lshape/whycon_lshape.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <ros/console.h>

#include <iostream>

namespace whycon_lshape
{

namespace { static int window_size = 25; }

WhyConLShape::WhyConLShape()
: maFiltRailU(window_size),
  maFiltRailV(window_size),
  maFiltToolU(window_size),
  maFiltToolV(window_size),
  maFiltWallU(window_size),
  maFiltWallV(window_size),
  maFiltWallInclU(window_size),
  maFiltWallInclV(window_size)
{
}

void WhyConLShape::update(double timestamp,
  const std::list<Eigen::Vector3d> & markers_position,
    const std::list<Eigen::Quaterniond> & markers_orientation)
{
  WhyConMarkers_.clear();
  std::list<Eigen::Vector3d>::const_iterator it_marker_position;
  std::list<Eigen::Quaterniond>::const_iterator it_marker_orientation;
  if (cntrRun == 0){
    nrMarkersWhycon = (int)markers_position.size();
    MarkersPositionPrev = Eigen::MatrixXd::Zero(3,nrMarkersWhycon);
    frozen = Eigen::VectorXi::Zero(nrMarkersWhycon);
    ROS_ERROR_STREAM("WhyCon works with "<< nrMarkersWhycon<<" markers");
  }
  for (unsigned int i = 0; i < markers_position.size(); ++i)
  {
    it_marker_position = markers_position.begin();
    std::advance(it_marker_position, i);
    it_marker_orientation = markers_orientation.begin();
    std::advance(it_marker_orientation, i);
    WhyConMarkers_.push_back(
      WhyConMarker(timestamp, (*it_marker_position), (*it_marker_orientation)));
  }
  LShapesDetection();
  cntrRun += 1;
}

unsigned int WhyConLShape::WhyConMarkersNr()
{
  return WhyConMarkers_.size();
}

unsigned int WhyConLShape::LShapesNr()
{
  return LShapesIdxs.size();
}

const WhyConMarker & WhyConLShape::iWhyConMarker(unsigned int i)
{
  return WhyConMarkers_[i];
}

std::tuple<int, std::vector<int>, Eigen::Vector2i, std::vector<int>, std::vector<Eigen::Vector3d>, std::vector<Eigen::Quaterniond> > WhyConLShape::LShapeDetector()
{
  return std::make_tuple(detectedLShapes, idx, ToolWallIdx, LShapesIdxs, LShapesPosition, LShapesOrientation);
}

void WhyConLShape::LShapesDetection()
{
    // this function detects nrLShapes LShape's and then quits
    detectedLShapes = 0;
    idx.clear();
    LShapesIdxs.clear();
    LShapesPosition.clear();
    LShapesOrientation.clear();
    bool L_found[4] = {false, false, false, false};
    std::vector<Eigen::Vector3d> LVectors;
    // try all points as the knot point
    for (unsigned int i=0;i<nrMarkersWhycon;i++){
      Eigen::Vector3d p0;
      LVectors.clear();
      p0 = WhyConMarkers_[i].position();
      // compute all vectors pointing to the knot point
      for(unsigned int j=0;j<nrMarkersWhycon;j++){
        Eigen::Vector3d interPos;
        interPos = WhyConMarkers_[j].position();
        if (i!=j){
          LVectors.push_back(interPos - p0);
        }
        // check if there are any frozen markers
        if (i == 0 && cntrRun > 0){
          if ((WhyConMarkers_[j].position() - MarkersPositionPrev.col(j)).lpNorm<Eigen::Infinity>()<1e-8){
            frozen[j] = 1;
            // ROS_ERROR_STREAM("frozen: "<<j<<" "<<(WhyConMarkers_[j].position() - MarkersPositionPrev.col(j)).lpNorm<Eigen::Infinity>()<<" "<<(WhyConMarkers_[j].position() - MarkersPositionPrev.col(j)).transpose()<<" "<<MarkersPositionPrev.col(j).transpose()<<" "<<WhyConMarkers_[j].position().transpose());
          }
          else frozen[j] = 0;
          MarkersPositionPrev.col(j) = WhyConMarkers_[j].position();
        }
      }
      // ROS_ERROR_STREAM("frozen: "<<frozen.transpose());
      // check if any of these vectors are orthogonal to each other, not optimized
      bool L_found_ = false;
      for(unsigned int j=0;j<LVectors.size();j++){
        for(unsigned int k=j+1;k<LVectors.size();k++){
          double dotProduct = (LVectors[j]).dot(LVectors[k]);
          // ROS_ERROR_STREAM("findLShape: "<<i<<" "<<j<<" "<<k<<" dot: "<<dotProduct<<" "<<fabs(dotProduct)<<"; length: "<<LVectors[j].norm()<<" "<<LVectors[k].norm()<<" lengtherror: "<<std::abs(LVectors[j].norm()-LVectors[k].norm()));
          // if they are orthogonal, assign the indices, stop loop
          if (std::abs(dotProduct) < 0.0005 && fabs(LVectors[j].norm()-LVectors[k].norm())<0.005){
            /// indeces of vectors of data.poses forming LShape
            Eigen::Vector3d idx_;
            // crosspoint
            idx_[0] = i;
            // wing points
            if (j>=i) { idx_[1] = j+1; }
            else { idx_[1] = j; }
            if (k>=i) { idx_[2] = k+1; }
            else { idx_[2] = k; }
            /// indeces of vectors of LVectors forming LShape
            int idx_x, idx_y;
            idx_x = j;
            idx_y = k;
            // check if there are any frozen markers, if so quit
            if (frozen[idx_[0]] == 1 || frozen[idx_[1]] == 1 || frozen[idx_[2]] == 1){
              // ROS_ERROR_STREAM("frozen: "<<frozen.transpose());
              continue;
            }
            // calculate unfiltered normal of LShape in order to get knowledge about x- and y- axis, in order to attribute to the correct filter memory
            Eigen::Vector3d normal;
            normal = (LVectors[idx_x]/LVectors[idx_x].norm()).cross(LVectors[idx_y]/LVectors[idx_y].norm());
            // if (detectedLShapes == 0){
            //   std::cout<<"wing1: "<<(LVectors[idx_x]/LVectors[idx_x].norm()).transpose()<<" wing2: "<<(LVectors[idx_x]/LVectors[idx_x].norm()).transpose()<<std::endl;
            //   std::cout<<"normal: "<<normal.transpose()<<std::endl;
            // }
            // normal/z-axis always has to point towards camera, define right hand system accordingly
            if (normal[2] > 0){
              Eigen::Vector3d interWing;
              double interIdx_;
              int interIdx;
              interIdx = idx_x;
              idx_x = idx_y;
              idx_y = interIdx;
              interIdx_ = idx_[1];
              idx_[1] = idx_[2];
              idx_[2] = interIdx_;
              normal = -normal;
            }
            // filter wing vectors;
            Eigen::Vector3d u;
            Eigen::Vector3d v;
            u = LVectors[idx_x];
            v = LVectors[idx_y];
            if (fabs(u.norm() - wingLengthLShapeRail)<wingLengthLShapeTolerance && fabs(v.norm() - wingLengthLShapeRail)<wingLengthLShapeTolerance){
              if (markersInitialized[0] == false){
                markersInitialized[0] = true;
                maFiltRailU.init(u);
                maFiltRailV.init(v);
              }
              if (L_found[0] == false){
                L_found[0] = true;
                maFiltRailU.filter(u);
                maFiltRailV.filter(v);
              }
              LShapesIdxs.push_back(0);
            }
            else if (fabs(u.norm() - wingLengthLShapeTool)<wingLengthLShapeTolerance && fabs(v.norm() - wingLengthLShapeTool)<wingLengthLShapeTolerance){
              if (markersInitialized[1] == false){
                markersInitialized[1] = true;
                maFiltToolU.init(u);
                maFiltToolV.init(v);
              }
              if (L_found[1] == false){
                L_found[1] = true;
                maFiltToolU.filter(u);
                maFiltToolV.filter(v);
              }
              ToolWallIdx[0] = detectedLShapes;
              LShapesIdxs.push_back(1);
            }
            else if (fabs(u.norm() - wingLengthLShapeWall_0)<wingLengthLShapeTolerance && fabs(v.norm() - wingLengthLShapeWall_0)<wingLengthLShapeTolerance){
              if (markersInitialized[2] == false){
                markersInitialized[2] = true;
                maFiltWallU.init(u);
                maFiltWallV.init(v);
              }
              if (L_found[2] == false){
                L_found[2] = true;
                maFiltWallU.filter(u);
                maFiltWallV.filter(v);
              }
              ToolWallIdx[1] = detectedLShapes;
              LShapesIdxs.push_back(2);
            }
            else if (fabs(u.norm() - wingLengthLShapeWall_1)<wingLengthLShapeTolerance && fabs(v.norm() - wingLengthLShapeWall_1)<wingLengthLShapeTolerance){
              if (markersInitialized[3] == false){
                markersInitialized[3] = true;
                maFiltWallInclU.init(u);
                maFiltWallInclV.init(v);
              }
              if (L_found[3] == false){
                L_found[3] = true;
                maFiltWallInclU.filter(u);
                maFiltWallInclV.filter(v);
              }
              LShapesIdxs.push_back(3);
            }
            else{
              break;
            }
            normal = (u/u.norm()).cross(v/v.norm());
            idx.push_back((int)idx_[0]);
            idx.push_back((int)idx_[1]);
            idx.push_back((int)idx_[2]);
            Eigen::Matrix3d rotation_;
            rotation_.row(0) = (u/u.norm()).transpose();
            rotation_.row(1) = (v/v.norm()).transpose();
            rotation_.row(2) = (normal/normal.norm()).transpose();
            // orthogonalization method Kevin
            double angle = M_PI / 2. - std::acos(u.dot(v) / (u.norm() * v.norm()));
            Eigen::Vector3d axis = u.cross(v);
            axis = axis / axis.norm();
            angle = angle / 2.;
            Eigen::Vector3d urot = u * std::cos(angle) + axis.cross(u) * std::sin(-angle) +
              axis * axis.dot(u) * (1 - std::cos(angle));
            Eigen::Vector3d vrot = v * std::cos(angle) + axis.cross(v) * std::sin(angle) +
              axis * axis.dot(v) * (1 - std::cos(angle));
            Eigen::Vector3d right = urot / urot.norm();
            Eigen::Vector3d forward = vrot / vrot.norm();
            Eigen::Vector3d up;
            up = right.cross(forward);
            rotation_.row(0) = right.transpose();
            rotation_.row(1) = forward.transpose();
            rotation_.row(2) = up.transpose();
            LShapesOrientation.push_back(Eigen::Quaterniond(rotation_));
            LShapesPosition.push_back(p0);
            L_found_ = true;
            detectedLShapes = detectedLShapes + 1;
            break;
          }
        }
        if(L_found_ == true) break;
      }
      if(detectedLShapes == nrLShapes) break;
    }
    // check if an index appears twice in the index list
    for(unsigned int i=0;i<idx.size();i++){
      for (unsigned int j = i+1;j<idx.size();j++){
        if (idx[i] == idx[j]){
          Eigen::VectorXd u_reset;
          detectedLShapes = 0;
          // reset filter
          if (L_found[0] == true){
            maFiltRailU.resetLastFilterStep();
            maFiltRailV.resetLastFilterStep();
          }
          if (L_found[1] == true){
            maFiltToolU.resetLastFilterStep();
            maFiltToolV.resetLastFilterStep();
          }
          if (L_found[2] == true){
            maFiltWallU.resetLastFilterStep();
            maFiltWallV.resetLastFilterStep();
          }
          if (L_found[3] == true){
            maFiltWallInclU.resetLastFilterStep();
            maFiltWallInclV.resetLastFilterStep();
          }
          break;
        }
      }
      if (detectedLShapes == 0) break;
    }
  }

} // namespace whycon_lshape
