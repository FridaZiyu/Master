#include "Matrix.hpp"

#include <iostream>
#include <vector>
int main() {
  Matrix A;
  Matrix B(2, 2);
  std::vector<double> m = {1, 2,  3,  4,  5,  6,  7,  8,
                           9, 10, 11, 12, 13, 14, 15, 16};
  Matrix C(8, 2, m);
  A = C;
  A.print();
  B.print();
  C.print();
  cout << "The largest entry of Matrix C is " << C.max() << "\n";
  int C_r = 8;
  int C_c = 2;
  cout << "The smallest entry of Matrix C is " << C.min(C_r, C_c) << "\n";
  C.resize(4, 4);
  C.print();
  return 0;
}
