#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
class Matrix {
public:
  Matrix() { cout << "INFO::Constr. 'Matrix::Matrix()'\n"; }
  Matrix(int rows, int columns);
  Matrix(int rows, int columns, const std::vector<double> &data);
  ~Matrix() { cout << "~Matrix()" << endl; }
  void resize(int rows, int columns);
  double get(int r, int c) const;
  void set(int r, int c, double x);
  double max() const;
  double min() const;
  double max(const int &r, const int &c) const;
  double min(const int &r, const int &c) const;
  void print() const;

private:
  std::vector<double> _data;
  int _R = 0;
  int _C = 0;
};
