#include "Matrix.hpp"

#include <iostream>
#include <vector>
int main() {
  // matrix constructor
  Matrix A;
  Matrix B(2, 2);
  std::vector<double> m = {1, 2,  3,  4,  5,  6,  7,  8,
                           9, 10, 11, 12, 13, 14, 15, 16};
  Matrix C(8, 2, m);
  // copy matrix with assignment
  A = C;
  // print matrix
  cout << "Matrix A is:\n";
  A.print();
  cout << "------------------------\n";
  cout << "Matrix B is:\n";
  B.print();
  cout << "------------------------\n";
  cout << "Matrix C is:\n";
  C.print();
  cout << "------------------------\n";
  // find the largest entry of matrix, find the smallest entry of matrix and its
  // location
  cout << "The largest entry of Matrix C is " << C.max() << "\n";
  int C_r = 8;
  int C_c = 2;
  auto min = C.min(C_r, C_c);
  cout << "The smallest entry of Matrix C is at row " << C_r << " column "
       << C_c << " : " << min << "\n";
  cout << "------------------------\n";
  // resize matrix C and print it
  C.resize(4, 4);
  cout << "Matrix C after resize is:\n";
  C.print();
  return 0;
}
