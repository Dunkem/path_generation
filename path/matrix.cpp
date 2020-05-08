#include "matrix.h"

namespace onboard_planner{

Matrix::Matrix(int n){
  size = n;
  std::cout << "请输入多项式的X矩阵" << std::endl;
  for (int i = 1;i <= n;i++)
    for (int j = 1; j <= n; j++) {

      std::cin >> matrix[i][j];//录入矩阵
    }
}

bool Matrix::SolveMatrix(){

  //最外层循环遍历整个矩阵
  for (int i = 1; i <= size; i++) {

    if (GetMaxMainElement(i) > 0 && i != GetMaxMainElement(i)) {
      //交换行
      ExchangTwoRow(GetMaxMainElement(i),i);
    }

    std::cout << i << "th transform" <<std::endl;
    DisPlay();
    std:: cout << std::endl;

    //第二层循环遍历与上一层相邻的层
    for (int j = i+1; j <= size; j++) {
      //将在第k次消去的主元的第一个元素赋给temp临时变量
      double temp = matrix[j][i];
      //将第一元素置0
      matrix[j][i] = 0;
      //第三层循环遍历矩阵的列
      for (int k = i+1; k <= size+1; k++) {

        //根据矩阵消去公式依次肖元，成为上三角矩阵
        matrix[j][k] = matrix[j][k]-(temp / matrix[i][i]) * matrix[i][k];
      }
    }
  }

  //预先判断消去后的矩阵是否有确定解
  if (matrix[size][size] != 0) {

    double temp;
    //解得xn存入solution数组
    solution[1] = matrix[size][size+1] / matrix[size][size];
    for (int i =2; i <= size; i++) {

      //将bi赋给变量A
      double A = matrix[size-i+1][size+1];
      for (int k = 1,j = 1; k <i; j++,k++) {
        //做减法
        temp = A - solution[j] * matrix[size-i+1][size-k+1];
        //赋值使上面等式可连减
        A = temp;
      }
      //除以主对角线上的系数，得到xi
      solution[i] = temp / matrix[size-i+1][size-i+1];
    }
    return true;
  }
  return false;
}

double* Matrix::GetFirstMatrix(){
  double *p = &matrix[1][1];
  return p;
}

double* Matrix::GetSolution(){
  return solution;
}

int Matrix::GetSize(){
  return size;
}

void Matrix::DisPlay(){

  for (int k = 1; k <= size; k++) {
    for (int m = 1; m <=size+1; m++) {

      if (m==size+1) {
        std::cout << matrix[k][m] <<std::endl;
      }
      else {
        std::cout << matrix[k][m] << "\t";
      }
    }
  }
}
void Matrix::SetAugmetMatrix(double *BMatrix) {
  for (int i = 1; i <= size; i++) {
    matrix[i][size+1] = BMatrix[i];//
  }
}

//获取列最大元素
int Matrix::GetMaxMainElement(int currentCol) {
  double temp = 0;
  int max_row_main = 0;
  for (int i = currentCol; i <= size; i++) {
    if (temp < matrix[i][currentCol]) {
      temp = matrix[i][currentCol];
      max_row_main = i;
    }
  }
  return max_row_main;
}
//交换两行，避免除数过小
void Matrix::ExchangTwoRow(int row1, int row2){

  double temp_matrix = 0;
  for (int i = 1; i <= size+1; i++) {
    temp_matrix     = matrix[row1][i];
    matrix[row1][i] = matrix[row2][i];
    matrix[row2][i] = temp_matrix;
  }
}

}

