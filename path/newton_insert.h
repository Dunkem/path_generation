#ifndef PROJECT_NEWTONINSERT_H
#define PROJECT_NEWTONINSERT_H

#include<iostream>
#include<string>
#include<vector>

namespace onboard_planner {
class NewtonInsert {
 public:
  NewtonInsert(int n1, std::vector<double>& xp, std::vector<double>&X, std::vector<double>&Y, std::vector<double> &result);
  double DividedDifferences(int n, std::vector<double>&X, std::vector<double>&Y);

}; // NewtonInsert
} // onboard_planner

#endif //PROJECT_NEWTONINSERT_H
