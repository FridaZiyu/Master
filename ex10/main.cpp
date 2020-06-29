#include "Matrix.hpp"
#include <iostream>
#include <vector>

using std::cout;
int main() {
  // matrix constructor
  cout << "===========================================\n";
  Matrix A;
  A.AsciiRead("test.txt");
  cout << "Matrix A is:\n";
  A.print();
  cout << "===========================================\n";
  Matrix B;
  B = A + 2;
  cout << "Matrix B = A + 2 is:\n";
  B.print();
  cout << "===========================================\n";
  Matrix C = B * 10;
  cout << "Matrix C = B * 10 is:\n";
  C.print();
  cout << "===========================================\n";
  Matrix D = A + C;
  cout << "Matrix D = A + C is:\n";
  D.print();
  cout << "===========================================\n";
  Matrix E = D - B;
  cout << "Matrix E = D - B is:\n";
  E.print();
  cout << "===========================================\n";
  cout << E(2,2) << "\n";
  E.resize(3,2);
  Matrix F = D - E;
  return 0;
}
