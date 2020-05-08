#include <vector>
#include "newton_insert.h"

int main() {
  int n,n1;
  std::cout << "请输入插值点的个数" << std::endl;
  std::cin >> n;
  std::vector<double>X(n, 0);
  std::vector<double>Y(n, 0);

  std::cout << "请输入插值点X[i]的值" << std::endl;
  for (int i = 0; i<n; i++) {
    std::cin >> X[i] ;
  }
  std::cout << "请输入插值点Y[i]的值" << std::endl;
  for (int i = 0; i<n; i++) {
    std::cin >> Y[i];
  }
  std::cout << "请输入所求点的个数" << std::endl;
  std::cin >> n1;
  std::vector<double> xp(n1, 0);
  std::vector<double> result(n1, 0);
  std::cout << "请输入所求插值点xp[i]的值：" << std::endl;
  for (int i = 0; i<n1; i++) {
    std::cin >> xp[i];
  }
  onboard_planner::NewtonInsert Newton(n1,xp, X, Y,result);
  std::cout << "输出所求插值点的函数值：" << std::endl;
  for (int h = 0; h < n1; h++) {
    std::cout<< result[h] << std::endl;
  }

  return 0;
}