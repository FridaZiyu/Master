#include "Fourierseries.hpp"
#include "Matrix.hpp"
#include <vector>
int main() {
  // Read matrix from file/or direcly read Fourier paramters file
  Matrix coef;
  coef.AsciiRead("coef.txt");
  Fourierseries Fourier(5, 0.5, coef);
  // Fourier.AsciiRead();
  std::vector<double> time = {1, 2, 3, 4, 5};
  Matrix t(5, 1, time);
  // synthesis
  Matrix L;
  Fourier.getFunctionalValues(t, L);
  std::cout<<"========================================================\n";
  std::cout << "Synthetic function value:\n";
  L.print();
  // analysis
  Matrix B;
  Fourier.getDesignMatrix(t, B);
  std::cout<<"========================================================\n";
  std::cout<<"The design matrix for the given points t with respect to unknown coefficients:\n";
  B.print();
  return 0;
}
