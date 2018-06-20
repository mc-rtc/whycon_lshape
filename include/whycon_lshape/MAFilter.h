#pragma once
#include <eigen3/Eigen/Core>
#include <queue>
#include <utility>

namespace whycon_lshape
{

  /** Moving average filter */
  struct MAFilter
  {
    public:
      MAFilter(int windowSize);
      void filter(Eigen::Ref<Eigen::VectorXd> x);
      void resetLastFilterStep();
    private:
      int windowSize;
      Eigen::MatrixXd window;
      Eigen::VectorXd window_prev;
      int cntr;
      void init(const Eigen::Ref<const Eigen::VectorXd> initVal);
  };

} // namespace whycon_lshape
