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
{
}

void WhyConLShape::add_lshape(const std::string & name, double wl)
{
  for(const auto & s : shapes_)
  {
    if(s.name == name)
    {
      ROS_ERROR_STREAM("An L-shape named " << name << " has already been added to the detector");
      return;
    }
  }
  shapes_.emplace_back(name, wl);
}

void WhyConLShape::update(size_t idx, const Eigen::Vector3d & pos, const Eigen::Quaterniond & ori)
{
  if(idx >= markers_.size())
  {
    markers_.resize(idx + 1);
  }
  markers_[idx].update(pos, ori);
  iter_ += 1;
}

const std::vector<LShape> & WhyConLShape::detect()
{
  LShapesDetection();
  return shapes_;
}

void WhyConLShape::LShapesDetection()
{
  for(auto & shape : shapes_)
  {
    shape.found = false;
  }
  for(size_t i = 0; i < markers_.size(); ++i)
  {
    // try all points as the knot point
    std::vector<Eigen::Vector3d> LVectors;
    Eigen::Vector3d p0 = markers_[i].position();
    // compute all vectors pointing to the knot point
    for(size_t j = 0; j < markers_.size(); ++j)
    {
      if(i == j) { continue; }
      LVectors.push_back(markers_[j].position() - p0);
    }
    // check if any of these vectors are orthogonal to each other, not optimized
    bool L_found_ = false;
    for(size_t j = 0; j < LVectors.size() && !L_found_; j++)
    {
      for(size_t k = j+1; k < LVectors.size() && !L_found_; k++)
      {
        double dotProduct = (LVectors[j]).dot(LVectors[k]);
        // if they are orthogonal, assign the indices, stop loop
        if (std::abs(dotProduct) < 0.0005 && std::abs(LVectors[j].norm()-LVectors[k].norm())<0.005)
        {
          /// indices of vectors of data.poses forming LShape
          std::array<size_t, 3> idx = {{i, j, k}};
          size_t idx_x = j; size_t idx_y = k;
          // idx_x/idx_y are LVectors indices but idx are markers_ indices
          if(idx[1] >= i) { idx[1] += 1; }
          if(idx[2] >= i) { idx[2] += 1; }
          // Continue searching if one of the marker is frozen
          if(std::any_of(idx.begin(), idx.end(),
                         [this](const size_t & idx)
                         {
                           return markers_[idx].frozen();
                         }))
          {
            continue;
          }
          // calculate unfiltered normal of LShape in order to get knowledge about x- and y- axis, in order to attribute to the correct filter memory
          Eigen::Vector3d normal = (LVectors[idx_x]/LVectors[idx_x].norm()).cross(LVectors[idx_y]/LVectors[idx_y].norm());
          // normal/z-axis always has to point towards camera, define right hand system accordingly
          if (normal[2] > 0)
          {
            normal = -normal;
            std::swap(idx[1], idx[2]);
            std::swap(idx_x, idx_y);
          }
          // filter wing vectors;
          auto & u = LVectors[idx_x];
          auto & v = LVectors[idx_y];
          LShape * lshape = nullptr;
          for(auto & shape : shapes_)
          {
            if(std::abs(u.norm() - shape.wing_length) < tolerance_ &&
               std::abs(v.norm() - shape.wing_length) < tolerance_ &&
               !shape.found)
            {
              shape.found = true;
              shape.filter_x.filter(u);
              shape.filter_x.filter(v);
              shape.markers = idx;
              lshape = &shape;
              break;
            }
          }
          if(lshape == nullptr) { continue; }
          normal = (u/u.norm()).cross(v/v.norm());
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
          lshape->ori = rotation_;
          lshape->pos = p0;
          L_found_ = true;
        }
      }
    }
  }
  // check if an index appears twice in the index list
  for(size_t i = 0; i < shapes_.size(); ++i)
  {
    auto & shape = shapes_[i];
    if(!shape.found) { continue; }
    for(size_t j = i + 1; j < shapes_.size(); ++j)
    {
      auto & shape2 = shapes_[j];
      if(!shape2.found) { continue; }
      if(shape.markers[0] == shape2.markers[0] ||
         shape.markers[0] == shape2.markers[1] ||
         shape.markers[0] == shape2.markers[2] ||
         shape.markers[1] == shape2.markers[0] ||
         shape.markers[1] == shape2.markers[1] ||
         shape.markers[1] == shape2.markers[2] ||
         shape.markers[2] == shape2.markers[0] ||
         shape.markers[2] == shape2.markers[1] ||
         shape.markers[2] == shape2.markers[2])
      {
        for(auto & s : shapes_)
        {
          if(s.found)
          {
            s.filter_x.resetLastFilterStep();
            s.filter_y.resetLastFilterStep();
          }
          s.found = false;
        }
      }
    }
  }
}

} // namespace whycon_lshape
