#include "Matrix.hpp"
#include <iostream>
#include <vector>

using std::cout;
int main() {
  // matrix constructor
  cout << "===========================================\n"; 
  try{
	  Matrix A;
	  A.AsciiRead("test.txt");
	  #ifdef VERBOSE
	  cout << "Matrix A is:\n";
	  A.print();
	  #endif
	  cout << "===========================================\n";
	  //test operations
	  Matrix B;
	  B = A + 2;
	  Matrix C = B * 10;
	  Matrix D = A + C;
	  Matrix E = D - B;
	  #ifdef VERBOSE
	  cout << "===========================================\n";
	  cout << "Matrix B = A + 2 is:\n";	  
	  B.print();
	  cout << "===========================================\n";
	  cout << "Matrix C = B * 10 is:\n";
	  C.print();
	  cout << "===========================================\n";	  
	  cout << "Matrix D = A + C is:\n";
	  D.print();
	  cout << "===========================================\n";	  
	  cout << "Matrix E = D - B is:\n";	  
	  E.print();
	  cout << "===========================================\n";
	  #endif
	  double a;
	  a = E(0,0);
	  E(1,1) = a;
	  #ifdef VERBOSE	  
	  E.print();
	  cout << "===========================================\n";
	  #endif
	  //try illegal expression
	  /*
	  Matrix F(5,5);
	  A += F; //Matrix size not agreement
	  */ 
	  double e = A.get(10,10); //Index exceeds array bounds
	  
	  }
  catch (std::logic_error& ex)
  {
	  std::cerr << "Logic error: " << ex.what() << std::endl;
	  return (EXIT_FAILURE);
  }
  catch (std::exception& ex) {
	  std::cerr << "Other Error: " << ex.what() << "\n";
	  return (EXIT_FAILURE);
	  } catch (...) { // and everything eles
	  std::cerr << "Error: unknown exception\n";
	  return (EXIT_FAILURE);
	  }
	  return (EXIT_SUCCESS);
}
