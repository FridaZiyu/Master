#include "Matrix.hpp"
#include <algorithm>
#include <vector>

using std::cout;
Matrix::Matrix(int rows, int columns) : _R(rows), _C(columns) {
  cout << "INFO::Constr. 'Matrix::Matrix(rows,columns)'\n";
  _data.resize(_R * _C);
  std::fill(_data.begin(), _data.end(), 0);
}

Matrix::Matrix(int rows, int columns, const std::vector<double> &data)
    : _R(rows), _C(columns), _data(data) {
  cout << "INFO::Constr. 'Matrix::Matrix(rows,columns,data)'\n";
}

void Matrix::resize(int rows, int columns) {
  _R = rows;
  _C = columns;
}

double Matrix::get(int row, int column) const {
  if (row > _R || column > _C) {
    cout << "The element doesn't exist!\n";
    return 0;
  } else {
    int index = _R * (column - 1) + row - 1;
    return (_data[index]);
  }
}

void Matrix::set(int row, int column, double x) {
  if (row > _R || column > _C)
    cout << "The element doesn't exist!\n";
  else {
    int index = _R * (column - 1) + row - 1;
    _data[index] = x;
  }
}

double Matrix::max() const {
  auto maximum = std::max_element(_data.begin(), _data.end());
  return (*maximum);
}

double Matrix::min() const {
  auto minimum = std::min_element(_data.begin(), _data.end());
  return (*minimum);
}

double Matrix::max(const int &r, const int &c) const {
  auto maximum = std::max_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), maximum);
  int R = loc % _R;
  int C = loc / _R;
  cout << "at row " << R << " column " << C << " : ";
  return (*maximum);
}
double Matrix::min(const int &r, const int &c) const {
  auto minimum = std::min_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), minimum);
  int R = loc % _R;
  int C = loc / _R;
  cout << "at row " << R << " column " << C << " : ";
  return (*minimum);
}

void Matrix::print() const {
  cout << "[";
  for (int i = 0; i < _R - 1; i++) {
    for (int j = 0; j < _C - 1; j++)
      cout << _data[_R * j + i] << " ";
    cout << _data[_R * (_C - 1) + i] << ";\n";
    cout << " ";
  }
  for (int j = 0; j < _C - 1; j++)
    cout << _data[_R * (j + 1) - 1] << " ";
  cout << _data[_R * _C - 1] << "]; % "
       << "dim " << _R << "*" << _C << "\n";
}
