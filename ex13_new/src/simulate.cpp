#include "Fourierseries.hpp"
#include "Matrix.hpp"
#include <cmath>
#include <random>
#include <vector>
using std::cin;
using std::cout;
int main() {
  // Read the control points and true parameters
  Matrix CP, Coef;
  CP.AsciiRead("txt/ControlPoints.txt");
  Coef.AsciiRead("txt/FourierCoefficients.txt");
  // Generate a Fourierseries object.
  double w, sigma;
  /**********/
  cout << "Please input the fundamental frequency of Fourier Series:\n";
  cin >> w;
  cout << "Please input the variance factor:\n";
  cin >> sigma;
  /**********/
  int n;
  n = (Coef.rows() - 1) / 2; // maximum order
  Fourierseries Fourier(n, w, Coef);
  Matrix Observ;
  Fourier.getFunctionalValues(CP, Observ);

  Observ.AsciiWrite("txt/TrueObservation.txt");

  // Simulated observation
  std::random_device r; // seed
  std::mt19937 myBasicGenerator(r());
  std::normal_distribution<double> aNormalDistribution(0, sqrt(sigma));

  Matrix Noise(CP.rows(), 1);
  for (int i = 0; i < CP.rows(); i++)
    Noise(i, 0) = aNormalDistribution(myBasicGenerator);

  Matrix Simu;
  Simu = Observ + Noise;
  Simu.AsciiWrite("txt/SimulatedObservation.txt");

  // Store w and sigma as well
  std::vector<double> set{w, sigma};
  Matrix Setting(2, 1, set);
  Setting.AsciiWrite("txt/Setting.txt");
  return 0;
}
