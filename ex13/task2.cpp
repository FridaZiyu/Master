#include "Fourierseries.hpp"
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
  double w = 0.5;
  Fourierseries Fourier(n_max, w);
  //
}
