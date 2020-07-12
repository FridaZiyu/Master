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
    Matrix C(2, 4, data);
    C.transpose();
    cout << "Matrix A is:\n";
    A.print();
    cout << "Matrix B is:\n";
    B.print();
    cout << "Matrix C is:\n";
    C.print();
    cout << "===========================================\n";
    C += A;
    cout << "C += A:\n";
    C.print();
    cout << "===========================================\n";
    Matrix D = A * B;
    cout << "Matrix D = A * B is:\n";
    D.print();
    Matrix E(A.get_rows(), A.get_rows());
    E.isSymmProductOf(A, 'N');
    cout << "A * A is:\n";
    E.print();
    E.plusProductOf(B, A, 'T', 'T', 2);
    cout << "2 * B' * A' is:\n";
    cout << "===========================================\n";
    cout << "B * A is:\n";
    E = B * A;
    E.print();
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
