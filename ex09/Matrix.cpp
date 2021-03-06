#include "Matrix.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <vector>
using std::cout;
using std::string;
Matrix::Matrix() {
  cout << "INFO::Constr. Empty Matrix\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  totalMemory();
}
Matrix::Matrix(int rows, int columns) : _R(rows), _C(columns) {
  cout << "INFO::Constr. Empty Matrix with size (" << rows << ',' << columns
       << ")\n";
  _data.resize(_R * _C);
  std::fill(_data.begin(), _data.end(), 0);
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  totalMemory();
}

Matrix::Matrix(int rows, int columns, const std::vector<double> &data)
    : _R(rows), _C(columns), _data(data) {
  cout << "INFO::Constr. A Matrix with size (" << rows << ',' << columns
       << ")\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  totalMemory();
}

// copy constructor
Matrix::Matrix(const Matrix &m) {
  _R = m._R;
  _C = m._C;
  _data = m._data;
  cout << "INFO::Copy Constr. Copy a Matrix with size (" << _R << ',' << _C
       << ")\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  totalMemory();
}
// '=' operator
Matrix &Matrix::operator=(const Matrix &m) {
  cout << "INFO::Custom operator '='. Copy a Matrix with size (" << m._R << ','
       << m._C << ")\n";
  total_m = total_m - _data.size() * sizeof(_data[0]);

  _R = m._R;
  _C = m._C;
  _data = m._data;

  total_m = total_m + _data.size() * sizeof(_data[0]);
  totalMemory();

  return (*this);
}

// Deconstructor
Matrix::~Matrix() {
  total_m = total_m - _data.size() * sizeof(_data[0]) - 2 * 4;
  totalMemory();
}
void Matrix::resize(int rows, int columns) {
  if (rows * columns != _R * _C) {
    std::cerr << "Error! Change the total number of element in matrix.\n";
    return;
  }
  _R = rows;
  _C = columns;
}

double Matrix::get(int row, int column) const {
  if (row > _R || column > _C) {
    cout << "The element doesn't exist!\n";
    return 0;
  } else {
    int index = _R * column + row;
    return (_data[index]);
  }
}

void Matrix::set(int row, int column, double x) {
  if (row > _R || column > _C)
    cout << "The element doesn't exist!\n";
  else {
    int index = _R * column + row;
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

double Matrix::max(int &r, int &c) const {
  auto maximum = std::max_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), maximum);
  r = loc % _R;
  c = loc / _R;
  return (*maximum);
}
double Matrix::min(int &r, int &c) const {
  auto minimum = std::min_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), minimum);
  r = loc % _R;
  c = loc / _R;
  return (*minimum);
}
// IO
void Matrix::AsciiRead(const string filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Error! Can't open file:" << filename << '\n';
    return;
  }
  total_m = total_m - _data.size() * sizeof(_data[0]); // calculate total_m
  in >> _R;
  in >> _C;
  _data.resize(_R * _C);
  int i = 0;
  while (!in.eof() && i < _R * _C) {
    in >> _data.at(i);
    i++;
  }
  cout << "INFO::AsciiRead. Read a Matrix(" << _R << ',' << _C
       << ") from file.\n";
  total_m = total_m + _data.size() * sizeof(_data[0]);
  totalMemory();
}
void Matrix::AsciiWrite(const string filename) {
  std::ofstream out(filename);
  if (!out.is_open()) {
    std::cerr << "Error! Can't open file:" << filename << '\n';
    return;
  }
  out << _R << std::endl;
  out << _C << std::endl;
  out << std::setprecision(10);
  std::copy(_data.begin(), _data.end(),
            std::ostream_iterator<double>(out, "\n"));
  cout << "INFO::AsciiWrite. Write Matrix in file '" << filename << "'\n";
}
void Matrix::BinaryRead(const string filename) {
  std::fstream in(filename, std::ios_base::in | std::ios_base::binary);
  if (!in.is_open()) {
    std::cerr << "Error! Can't open file:" << filename << '\n';
    return;
  }
  total_m = total_m - _data.size() * sizeof(_data[0]); // calculate total_m
  in.read(reinterpret_cast<char *>(&_R), sizeof(_R));
  in.read(reinterpret_cast<char *>(&_C), sizeof(_C));
  _data.resize(_R * _C);
  in.read(reinterpret_cast<char *>(&_data[0]), _data.size() * sizeof(_data[0]));

  cout << "INFO::BinaryRead. Read a Matrix(" << _R << ',' << _C
       << ") from file.\n";
  total_m = total_m + _data.size() * sizeof(_data[0]);
  totalMemory();
}
void Matrix::BinaryWrite(const string filename) {
  std::ofstream out(filename, std::ios_base::binary);
  if (!out.is_open()) {
    std::cerr << "Error! Can't open file:" << filename << '\n';
    return;
  }
  out.write(reinterpret_cast<char *>(&_R), sizeof(_R));
  out.write(reinterpret_cast<char *>(&_C), sizeof(_C));
  out.write(reinterpret_cast<char *>(&_data.front()),
            _data.size() * sizeof(_data.front()));
  cout << "INFO::BinaryWrite. Write Matrix in file '" << filename << "'\n";
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

int Matrix::total_m = 0;
int Matrix::totalMemory() {
  cout << "Current memory usage: " << total_m << " Byte\n";
  return total_m;
}
