#include <iostream>
#include <random>
#include "Matrix.hpp"
#include <string>
#include "Fourierseries.hpp"
int main(){
	int xmin = 1;
	int xmax = 100;
	int N=1000;
	std::random_device r;
	std::mt19937 myBasicGenerator(r());
	std::uniform_int_distribution<int> aUniDist(xmin,xmax);
	Matrix A(N,1);
	for (int i=0;i<N;i++)
		A(i,0)=aUniDist(myBasicGenerator);
	std::string fileName = "control_points";
	A.Binarywrite(fileName);
	int n_max = 200;
	double w = 0.5;
	Fourierseries(n_max,w);
	
}
