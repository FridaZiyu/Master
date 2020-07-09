#include "Matrix.hpp"
#include "Fourierseries.hpp"
#include <vector>
int main(){
	//Read matrix from file/or direcly read Fourier paramters file	
	Matrix coef;
	coef.AsciiRead("coef.txt"); 
	Fourierseries Fourier(5,0.5,coef);
	//Fourier.AsciiRead();
	std::vector<double> time = {1,2,3,4,5};
	Matrix t(5,1,time);
	//synthesis
	Matrix L;
	Fourier.getFunctionalValues(t,L);
	L.print();
	//analysis
	Matrix B;
	Fourier.getDesignMatrix(t,B);
	B.print();
	return 0;
}
