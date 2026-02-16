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


  ////////////// DYNAMIC MATRIX ////////////////////////

  // define a dynamic matrix, explicit decloaration
  Matrix<float, Dynamic, Dynamic> MatrixB;
  
  // typedef decloration
  MatrixXf B1;

  // constructor, allocate memory? but do not initialize
  MatrixXd MatrixC(10,10);


  
  
  //creating matrix (2,2)

  MatrixXd matrixC1 (2,2);
  matrixC1(0,0) = 1;
  matrixC1(0,1) = 2;
  matrixC1(1,0) = 3;
  matrixC1(1,1) = 4;

  cout << matrixC1 << "\n\n";

  // another way 

  Matrix4f matrixD;
  matrixD << 1,2,3,4,
  5,6,7,8,
  9,10,11,12,
  13,14,15,16;
  cout << matrixD << "\n\n";



  // matrix of zeros
  int rows = 5;
  int cols = 5;

  MatrixXf matrixx1zeros;
  matrixx1zeros.setZero(rows, cols);
  cout << matrixx1zeros << "\n\n";
  // another option;
  MatrixXf matrix_of_zeros;
  matrix_of_zeros = MatrixXf::Zero(rows,cols);
  cout << matrix_of_zeros << "\n\n";

  // matrix of ones
  MatrixXf matrix1one;
  matrix1one.setOnes(rows,cols);
  cout << matrix1one << "\n\n";
  // another way
  MatrixXf matrix2ones;
  matrix2ones = MatrixXf::Ones(rows,cols);
  cout << matrix2ones << "\n\n";








}