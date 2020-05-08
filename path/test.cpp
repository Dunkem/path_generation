#include <iostream>

#include "path_generation.h"

const double PI = 3.1415926;

int main() {

  std::cout << "-----Lagrange插值法求解-----" << std::endl;
  int num;
  double x;
  std::cout << "输入已知的点的个数" << std::endl;

  std::cin >> num;
  std::cout << "输入要求的Y值对应的X值" << std::endl;
  std::cin >> x;
  onboard_planner::LagrangeInsert lagrange(num,x);
  lagrange.CalculateLValue();
  double y = lagrange.AttainResult();
  std::cout << "求解结果：" << "F(x)=" << y << std::endl;

  return 0;

};