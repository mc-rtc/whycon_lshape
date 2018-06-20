#include <whycon_lshape/MAFilter.h>

#include <iostream>

namespace whycon_lshape
{

  MAFilter::MAFilter(int windowSize_)
  : windowSize(windowSize_)
  {
  }

  void MAFilter::init(const Eigen::VectorXd & initVal)
  {
    window = initVal.asDiagonal() * Eigen::MatrixXd::Ones(initVal.size(), windowSize);
    window_prev = Eigen::VectorXd::Zero(initVal.size());
  }

  void MAFilter::filter(Eigen::Ref<Eigen::VectorXd> x)
  {
    window_prev = window.col(cntr);
    window.col(cntr) = x;
    x = window.rowwise().sum() / windowSize;
    cntr = (cntr + 1) % windowSize;
  }

  void MAFilter::resetLastFilterStep()
  {
    if(cntr == 0) { cntr = windowSize - 1; }
    else { cntr = cntr - 1; }
    window.col(cntr) = window_prev;
    cntr = (cntr + 1) % windowSize;
  }
}
