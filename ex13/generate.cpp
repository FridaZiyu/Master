#include "Matrix.hpp"
#include <iostream>
#include <random>
#include <string>
int main() {
  int xmin = 1;
  int xmax = 100;
  int N = 1000;
  std::random_device r;
  std::mt19937 myBasicGenerator(r());
  std::uniform_int_distribution<int> aUniDist(xmin, xmax);
  Matrix A(N, 1);
  for (int i = 0; i < N; i++)
    A(i, 0) = aUniDist(myBasicGenerator);
  A.Asciiwrite("control_points.txt");
  int n_max = 200;
  Matrix x(2*n_max+1, 1);
  for (int j = 0; j<2*n_max+1; j++)
	  x(j,0) = aUniDist(myBasicGenerator);
  x.Asciiwrite("true_para.txt");
  //double w = 0.5;
  //Fourierseries Fourier(n_max, w);
  
}
