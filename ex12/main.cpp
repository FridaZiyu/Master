#include "Matrix.hpp"
#include <vector>
#include <iostream>
using std::cout;
int main(){	
	std::vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8}; //2*4
	std::vector<double> n = {8, 7, 6, 5, 4, 3, 2, 1}; //2*4
	cout<<"--------------------------------------\n";
	cout<<"Matrix A:\n";
	Matrix A(4,2,m);
	A.print();
	cout<<"Matrix sysA(A*A'):\n";
	Matrix sysA;
	sysA.isSymmProductOf(A, 'N');
	sysA.print();
	cout<<"Matrix sysAT(A'*A + I):\n";
	Matrix sysAT;
	sysAT.identity(A.columns());
	sysAT.plusSymmProductOf(A,'T');
	sysAT.print();
	cout<<"--------------------------------------\n";
	cout<<"Matrix B:\n";
	Matrix B (4,2,n);
	B.print();
	cout<<"Matrix C = A' * B:\n";
	Matrix C;
	C.isProductOf(A,B,'T','N');
	C.print();
	cout<<"Matrix C += A' * B:\n";
	C.plusProductOf(A,B,'T','N');
	C.print();
	cout<<"--------------------------------------\n";
	cout<<"C = A * B':\n";
	B.transpose();
	C = A * B;
	C.print();
	cout<<"C = A + B:\n";
	B.transpose();
	C = A + B;
	C.print();
	cout<<"A += B:\n";
	A += B;
	A.print();
	cout<<"A -= B:\n";
	A -=B;
	A.print();
	cout<<"--------------------------------------\n";	
}