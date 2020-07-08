#include "Matrix.hpp"
#include "tictoc.hpp"
#include <iostream>
#include <vector>

using std::cout;
int main() {
  TicToc myTime;
  cout << "===========================================\n";
  try {
	int test_num = 1000;
	Matrix A;	
	Matrix B(test_num-2,3);
	double t;
	double flop = 0;
	flop += 2; //size =1x1;
	/*
	A.AsciiRead("spd.txt"); 
	A.chol();
	A.print();*/
	for( int i = 2; i < test_num; i++){
	//create a positive matrix
	//myTime.tic();
	A.identity(i);
	A(0,0) = 4;
	A (1,1) = 5;
	A(0,i-1) = 0.5;
	//A(i-1,0) = 0.5;
	//tic
	myTime.tic();
	//A.print();
	A.chol();
	//A.print();
	t = myTime.toc();
	//toc
	//calculate flop
	flop += (i+1) * i;
	B(i-2,0) = i;
	B(i-2,1) = t; //time-> millisecond;
	if (t == 0)
		B(i-2,2) = 0;   //calculation time too small
	else
		B(i-2,2) = flop * 1000 / t ; //FLOPs/second
	}
	//B.AsciiWrite("performance.txt");
	B.BinaryWrite("performance_b");
    cout << "===========================================\n";
  } catch (std::logic_error &ex) {
    std::cerr << "Logic error: " << ex.what() << "\n";
    return (EXIT_FAILURE);
  } catch (std::exception &ex) {
    std::cerr << "Other Error: " << ex.what() << "\n";
    return (EXIT_FAILURE);
  } catch (...) { // and everything eles
    std::cerr << "Error: unknown exception\n";
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
