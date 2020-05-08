#ifndef PROJECT_MATRIX_H
#define PROJECT_MATRIX_H

#include <iostream>
#include<cmath>

namespace onboard_planner{

const int MN = 100;

class Matrix {

 public:
  /**
   *
   * @param k
   */
  Matrix(int k);

  /**
   *
   */
  void DisPlay();

  /**
   *
   * @param BMatrix
   */
  void SetAugmetMatrix(double *BMatrix);

  /**
   *
   * @return
   */
  bool SolveMatrix();//解矩阵，其中有消元和回代的过程

  /**
   *
   * @return
   */
  int GetSize();//获取矩阵的大小

  /**
   *
   * @return
   */
  double* GetSolution();//获得解的数组

  /**
   *
   * @return
   */
  double* GetFirstMatrix();//获取矩阵第一行第一列元素

  /**
   *
   * @param currentCol
   * @return
   */
  int GetMaxMainElement(int currentCol);//获取最大主元所在的行

  /**
   *
   * @param row1
   * @param row2
   */
  void ExchangTwoRow(int row1,int row2);//交互矩阵中的两行

 public:
  //! size of matrix
  int size;
  //! augmented matrix
  double matrix[MN][MN];
  //!  solutio of the equation
  double solution[MN];
};

}

#endif //PROJECT_MATRIX_H
