#pragma once
#include <mc_control/mc_controller.h>
#include <mc_control/api.h>
#include <mc_rbdyn/RobotLoader.h>
#include <queue>
#include <utility>

namespace augmented_whycon{
  struct bwFilter{
    public:
      bwFilter();
      // order, samples per second == frequency, cutoff frequency
      bwFilter(int _n, double _s, double _f, int MA_windowSize);
      void initMA_window(Eigen::VectorXd initVal);
      double filter(double x);
      Eigen::VectorXd filterMA(Eigen::VectorXd x);
      Eigen::VectorXd resetLastFilterStep();
    private:
      int n;
      double s;
      double f;
      double a;
      double a2;
      double r;
      double *A = (double *)malloc(n*sizeof(double));
      double *d1 = (double *)malloc(n*sizeof(double));
      double *d2 = (double *)malloc(n*sizeof(double));
      double *w0 = (double *)calloc(n, sizeof(double));
      double *w1 = (double *)calloc(n, sizeof(double));
      double *w2 = (double *)calloc(n, sizeof(double));
      int i;
      // moving average filter
      int MA_windowSize;
      Eigen::MatrixXd MA_window;
      Eigen::VectorXd MA_window_prev;
      int cntr = 0;
  };
}