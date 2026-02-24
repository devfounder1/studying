#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

int main() {

    setlocale(LC_ALL,"RU");
    
    MatrixXf A (5,2);
        
    A << 50,2,
        80,3,
        100,4,
        60,2,
        90,3;

    VectorXf y(5);
    y << 5,8,11,6,9;


    


    return 0;
}