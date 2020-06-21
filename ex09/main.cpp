#include "Matrix.hpp"

#include <iostream>
#include <vector>
int main() {
  // matrix constructor
  Matrix A;
  //Matrix B(2, 2);
  std::vector<double> m = {1, 2,  3,  4,  5,  6,  7,  8,
                           9, 10, 11, 12, 13, 14, 15, 16};
  Matrix C(8, 2, m);
  // copy matrix with assignment
  A = C;
  // print matrix
  /*
  cout << "Matrix A is:\n";
  A.print();
  cout << "------------------------\n";
  cout << "Matrix C is:\n";
  C.print();
  cout << "------------------------\n";
  */
  // resize matrix C and print it
  C.set(0,0,5.5);
  //cout << "Matrix C after resize is:\n";
  //C.print();
  //A.print();
  //cout <<"Size:" << sizeof(A) <<';' << Matrix::totalMemory() <<'\n';
  {
	  Matrix B(4,4, m);
	  B.print();
  }
  return 0;
}

