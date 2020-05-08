#ifndef PROJECT_PATH_GENERATION_H
#define PROJECT_PATH_GENERATION_H

#include <iostream>
#include<cmath>
#include <vector>

namespace onboard_planner {

//Lagrange
class LagrangeInsert {

 public:

  /**
   * @param n Number of points
   * @param x The value of the interpolation point
   */
  LagrangeInsert(int n, double x);

  /**
   * Calculate the value of each item of LagrangeInsert
   */
  void CalculateLValue();

  /**
   * Get the corresponding y value
   * @return
   */
  double AttainResult();

 public:
  //! Number of
  int size_;
  //! the value of the interpolation point
  double inter_x_;
  //! Lagrange coefficient eg: y = l_[0] * y_[0] + ...
  std::vector<double> l_;
  //! y value of points
  std::vector<double> y_;
  //! x value of points
  std::vector<double> x_;
}; // class LagrangeInsert
} // namespace onboard_planner

#endif //PROJECT_PATH_GENERATION_H
