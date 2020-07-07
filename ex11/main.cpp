#include "Matrix.hpp"
#include "tictoc.hpp"
#include <iostream>
#include <vector>

using std::cout;
int main() {
  // matrix constructor
  cout << "===========================================\n";
  try {
    TicToc t;
    Matrix A, B;
    A.AsciiRead("spd.txt");
    B.AsciiRead("nonspd.txt");
    cout << "===========================================\n";
    cout << "Original A:\n";
    A.print();
    cout << "The cholesky factor of A:\n";
    t.tic();
    Matrix LA = A.chol();
    auto time = t.toc()/1000.0;
    LA.print();
    cout<<"time:"<<time<<"flop:"<<A.getFlop()<<"\n";
    cout << "The performance is " << A.getFlop() / time << "FLOP/s \n";
    cout << "===========================================\n";
    cout << "Original B:\n";
    B.print();
    cout << "The cholesky factor of B:\n";
    Matrix LB = B.chol();
    LB.print();
  } catch (std::logic_error &ex) {
    std::cerr << "Logic error: " << ex.what() << std::endl;
    return (EXIT_FAILURE);
  } catch (std::exception &ex) {
    std::cerr << "Other Error: " << ex.what() << "\n";
    return (EXIT_FAILURE);
  } catch (...) { // and everything eles
    std::cerr << "Error: unknown exception\n";
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
