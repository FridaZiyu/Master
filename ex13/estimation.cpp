#include <iostream>
#include <vector>
int main() {
  Matrix simulate;
  estimate.AsciiRead("simulated_observ.txt");
  std::vector<double> l0;
  l0.assign(simulate._data.begin(), simulate._data.end() - 2);
  int size = simulate._data.size();
  int n_max = (size - 3) / 2;
  double omega0 = simulate._data[size - 2];
  double sigma = simulate._data[size - 1];
  Fourierseries Fourier(n_max, omega0, l0);
  Matrix t; // control points
  t.AsciiRead("control_points.txt");
  Matrix A; // design matrix
  Fourier.getDesignMatrix(t, A);
  Matrix temp_A(A);
  Matri l; // observations
  l.AsciiRead("true_observ.txt");
  // Matrix cov,N,n;
  Matrix x_; // estimated unknown parameters
  temp_A.chol();
  x_.solveWithCholReduced(temp_A);
  Matrix v_; // estimated residuals
  v_ = A * x_ - l;
  double r = 1000 - (2 * n_max + 1);
  Matrix s_ = v_.transpose() * v_.transpose() / r; // estimate variance factor
  Matrix N_inv = temp_A.invCholReduced();          // covariance of parameters

  return 0;
}
