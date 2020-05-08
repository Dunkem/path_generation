#include "path_generation.h"

namespace onboard_planner {

LagrangeInsert::LagrangeInsert(int n, double x) {
  size_ = n;
  inter_x_ = x;

  x_.resize(size_);
  y_.resize(size_);
  l_.resize(size_);

  for (int i = 0; i < size_; i++) {
    double temp_x;
    std::cout << "x" << i << "=";
    std::cin >> temp_x;
    x_[i] = temp_x;
    std::cout << std::endl;
  }

  for (int j = 0; j < size_; j++) {
    double temp_y;
    std::cout << "y" << j << "=";
    std::cin >> temp_y;
    y_[j] = temp_y;
    std::cout << std::endl;
  }
}

void LagrangeInsert::CalculateLValue() {

  for (int i = 0; i < size_; i++) {
    double temp = 1;

    for (int j = 0;j <size_; j++) {

      if (j == i) {
        continue;
      }
      else {
        double A=1;
        A = ((inter_x_-x_[j]) / (x_[i]-x_[j])) * temp;
        temp = A;
      }
    }

    l_[i] = temp;
  }
}

double LagrangeInsert::AttainResult() {
  double result = 0;
  for (int i = 0; i < size_; i++) {
    result += y_[i] * l_[i];
  }
  return result;
}
} // namespace onboard_planner
