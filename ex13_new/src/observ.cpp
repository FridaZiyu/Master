#include "Matrix.hpp"
#include <random>
#include <vector>
using std::cin;
using std::cout;
int main() {
  // generate control pointer
  // N uniformly distributed control points in range [Xmin,Xmax]
  int N;
  double Xmin, Xmax;
  /**********/
  cout << "Please input the number of control points:\n";
  cin >> N;
  cout << "Please input the lower and upper boundary of control points:\n";
  cin >> Xmin >> Xmax;
  /**********/
  // generate control points in a matrix
  Matrix CP(N, 1);
  std::random_device r; // seed
  std::mt19937 myBasicGenerator(r());
  std::uniform_real_distribution<double> aUniDist(Xmin, Xmax);
  for (int i = 0; i < N; i++)
    CP(i, 0) = aUniDist(myBasicGenerator);

  // store points in a file.
  CP.AsciiWrite("txt/ControlPoints.txt");

  int n; // maximum order of Fourier Series
  /**********/
  cout << "Please input the maximum order of Fourier Series:\n";
  cin >> n;
  /**********/
  // generate random parameters ai and bi, store in maxtix and write in a file
  std::uniform_real_distribution<double> paraUniDist(-2.0,
                                                     2.0); // ai,bi in [-2,2]
  double num = 2 * n + 1;
  Matrix Coef(num, 1);
  for (int i = 0; i < num; i++)
    Coef(i, 0) = paraUniDist(myBasicGenerator);
  Coef.AsciiWrite("txt/FourierCoefficients.txt");

  return 0; // If successful
}
