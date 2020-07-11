#include "Matrix.hpp"
#include <iostream>
#include <vector>

using std::cout;
int main() {
  cout << "===========================================\n";
  try {
    std::vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<double> data2 = {1, 3, 5, 7, 9, 11};
    Matrix A(4, 2, data);
    Matrix B(2, 3, data2);
    cout << "Matrix A is:\n";
    A.print();
    cout << "Matrix B is:\n";
    B.print();
    cout << "===========================================\n";
    Matrix C = A * B;
    cout << "Matrix C=A*B is:\n";
    C.print();
    Matrix D;
    D.plusSymmProductOf(A, 'N', 2);
    D.print();
    C.isSymmProductOf(A, 'N');
    cout << "A*A is:\n";
    C.print();
    C.plusProductOf(B, A, 'T', 'T', 2);
    cout << "2*B'*A' is:\n";
    cout << "===========================================\n";
    cout << "B*A is:\n";
    C = B * A;
    C.print();
  } catch (std::logic_error &ex) {
    std::cerr << "Logic error: " << ex.what() << "\n";
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
