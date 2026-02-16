#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

const float value = 1.1;

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



  // matrix of constants
  MatrixXf matrixconst;
  matrixconst = MatrixXf::Constant(rows,cols, value);
  cout << matrixconst << "\n\n";
  // another way
  MatrixXf matrix2const;
  matrix2const.setConstant(rows,cols,value);
  cout << matrix2const << "\n\n";


  // identity matrix, two aproches

  int rowNumbers = 10;
  int colNumbers = 10;

  MatrixXd matrixidentity;
  matrixidentity = MatrixXd::Identity(rowNumbers, colNumbers);
  cout << matrixidentity << "\n\n";

  MatrixXd matrixidentity1;
  matrixidentity1.setIdentity(rowNumbers,colNumbers);
  cout << matrixidentity1 << "\n\n";


  MatrixXd matrixV(4,4);
  matrixV << 101,102,103,104,
      105,106,107,108,
      109,110,111,112,
      113,114,115,116;
  // access thre matrix composesed of 1:2 rows and 1:2 colums of matrixV
  MatrixXd matrixVpartition = matrixV.block(0,0,2,2);
  cout << matrixVpartition << "\n\n";

  // берет отдельный блок в матрице 
  MatrixXd matrixVpartition2 = matrixV.block(1,1,2,2);
  cout << matrixVpartition2 << "\n\n";



  // accessing colums and rows of a matrix
  
  cout <<"\n\n" << "row 1 of matrixV is \n " << matrixV.row(0) << "\n";
  cout << "\n\n" << "column 1 of matrix is \n " << matrixV.col(1) << "\n\n"; 


  // create a diagonal matrix out of a vector 
  Matrix <double, 3,1> vector1;
  vector1 << 1,2,3;
  MatrixXd diagonalmatrix; 
  diagonalmatrix = vector1.asDiagonal();
  cout << "diagonal matrix is \n\n" << diagonalmatrix << "\n\n";


  // basic matrix opperations

  MatrixXd K1(2,2);
  MatrixXd K2(2,2);

  K1 << 1,2,3,4;
  K2 << 6,3,6,9;

  MatrixXd L = K1 + K2;
  cout << "summ of matrixes K1 and K2 : \n" << L << "\n\n";


  // matrix multiplication
  MatrixXd O = K1 * K2;
  cout << "multiplication of matrixes K1 and K2 : \n" << O << "\n\n";



  // multiplication by scalar
  int s1 = 2;
  MatrixXd F1;
  F1 = s1 * K1;
  cout << "matrix product of the scalar 2 and the matrix F1 : " << F1 << "\n\n"; 

}