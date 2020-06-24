#include "Matrix.hpp"
#include <iostream>
#include <vector>
//#include <string>
int main() {
  // matrix constructor
  std::cout << "===========================================\n";
  Matrix A;
  A.AsciiRead("test.txt"); 
  Matrix B = A;
  B.AsciiWrite("out1.txt");
  Matrix C(B);
  B.set(0,0,5.5);
  B.BinaryWrite("out2.txt");
  Matrix D;
  D.BinaryRead("out2.txt");
  std::cout << "===========================================\n";
  return 0;
}

