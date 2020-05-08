#include "newton_insert.h"

namespace onboard_planner {

NewtonInsert::NewtonInsert(int n1,
                          std::vector<double> &xp,
                          std::vector<double> &X,
                          std::vector<double> &Y,
                          std::vector<double> &result) {

  double temp1 = 0;
  for (int h = 0; h < n1; h++)
  {
    for (int i = 0; i < X.size(); i++)
    {
      double temp = 1;
      double f = DividedDifferences(i, X, Y);
      for (int j = 0; j < i; j++)
      {
        temp = temp*(xp[h] - X[j]);
      }
      temp1 += f*temp;
    }
    result[h] = temp1;
    temp1 = 0;
  }


}

double NewtonInsert::DividedDifferences(int n, std::vector<double> &X, std::vector<double> &Y) {

  double f = 0;
  double temp = 0;
  for (int i = 0; i<n + 1; i++)
  {
    temp = Y[i];
    for (int j = 0; j<n + 1; j++)
      if (i != j) temp /= (X[i] - X[j]);
    f += temp;
  }
  return f;

}

}
