#include "Fourierseries.hpp"
#include "Matrix.hpp"
#include <iostream>
int main() {
  double omega0 = 0.5;
  double sigma = 1;
  int N = 1000;
  Matrix t;
  A.AsciiRead("control_points.txt");
  Matrix x; // coefficients
  x.AsciiRead("true_para.txt");
  Fourierseries Fourier(200, omega0, x);
  Matrix L;
  Fourier.getFunctionalValues(t, L);
  L.AsciiWrite("true_observ.txt");
  std::default_random_engine myBasicGenerator(time(nullptr));
  std::normal_distribution<double> aNormalDistribution(0, sigma);
  std::vector<double> r(N, 0);
  for (int i = 0; i < N; i++)
    r[i] = aNormalDistribution(myBaxicGenerator);
  std::vector<double> true(L._data);
  std::transform(r.begin(), r.end(), true.begin(), true.end(),
                 std::plus<double>()); // adds together 2 vectors
  r.pushback(omega0);
  r.pushback(sigma);
  Matrix simulate(N + 2, 1, r);
  simulate.AsciiWrite("simulated_observ.txt");
  return 0;
}
