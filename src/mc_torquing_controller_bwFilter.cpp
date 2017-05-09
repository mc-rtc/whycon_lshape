#include <augmented_whycon/mc_torquing_controller_bwFilter.h>

namespace augmented_whycon{
  bwFilter::bwFilter(int _n, double _s, double _f, int MA_windowSize_) : n(_n), s(_s), f(_f), MA_windowSize(MA_windowSize_)
  {
    // butterworth filter
    n = n/2;
    a = tan(M_PI*f/s);
    a2 = a*a;
    for(i=0; i<n; ++i)
    {
      r = sin(M_PI*(2.0*i+1.0)/(4.0*n));
      s = a2 + 2.0*a*r + 1.0;
      A[i] = a2/s;
      d1[i] = 2.0*(1-a2)/s;
      d2[i] = -(a2 - 2.0*a*r + 1.0)/s;
    }
  }

  void bwFilter::initMA_window(Eigen::VectorXd initVal){
    MA_window = Eigen::MatrixXd::Ones(initVal.size(), MA_windowSize);
    MA_window_prev = Eigen::VectorXd::Zero(initVal.size());
    for (int i=0;i<initVal.size();i++) MA_window.row(i) = initVal[i] * MA_window.row(i);
  }

  double bwFilter::filter(double x)
  {
   for(i=0; i<n; ++i)
   {
     w0[i] = d1[i]*w1[i] + d2[i]*w2[i] + x;
     x = A[i]*(w0[i] + 2.0*w1[i] + w2[i]);
     w2[i] = w1[i];
     w1[i] = w0[i];
   }
   return x;
  }

  Eigen::VectorXd bwFilter::filterMA(Eigen::VectorXd x)
  {
    for (int i=0;i<x.size();i++){
      MA_window_prev(i) = MA_window.row(i)[cntr];
      MA_window.row(i)[cntr] = x[i];
      x[i] = MA_window.row(i).sum() / MA_windowSize;
    }
    if (cntr % MA_windowSize == MA_windowSize-1) {cntr = 0;}
    else {cntr = cntr + 1;}
    return x;
  }

  Eigen::VectorXd bwFilter::resetLastFilterStep()
  {
    if (cntr == 0) cntr = MA_windowSize - 1;
    else cntr -= 1;
    Eigen::VectorXd x = Eigen::Vector3d::Zero();
    for (int i=0;i<MA_window_prev.size();i++){
      MA_window.row(i)[cntr] = MA_window_prev(i);
      x[i] = MA_window.row(i).sum() / MA_windowSize;
    }
    if (cntr % MA_windowSize == MA_windowSize-1) {cntr = 0;}
    else {cntr = cntr + 1;}
    return x;
  }
}
