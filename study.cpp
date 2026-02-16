#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;


int main() {
  MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -10;
  m(1, 1) = m(1, 0) + m(0, 1);
  std::cout << m << "\n\n\n";

  // define 3x3 matrix of floats 
  Matrix<float, 3,3> matrixA;
  matrixA.setZero();
  cout << matrixA << "\n\n";
  
  // another way to define matrix 3x3
  Matrix3f matrixA1;
  matrixA1.setZero();
  cout << matrixA1 << "\n\n";




  // define a dynamic matrix, explicit decloaration
  Matrix<float, Dynamic, Dynamic> MatrixB;
  
  // typedef decloration
  MatrixXf B1;

  // constructor, allocate memory? but do not initialize
  MatrixXd MatrixC(10,10);

  






}