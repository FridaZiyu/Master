#include "Matrix.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <vector>
using std::cout;
using std::string;
Matrix::Matrix() {
  // cout << "INFO::Constr. Empty Matrix\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  // totalMemory();
}
Matrix::Matrix(int rows, int columns) : _R(rows), _C(columns) {
  if (rows < 1 || columns < 1)
    throw std::logic_error("size of matrix must >= 1");
  // cout << "INFO::Constr. Empty Matrix with size (" << rows << ',' << columns
  //     << ")\n";
  _data.resize(_R * _C);
  std::fill(_data.begin(), _data.end(), 0);
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  // totalMemory();
}

Matrix::Matrix(int rows, int columns, const std::vector<double> &data)
    : _R(rows), _C(columns), _data(data) {
  // cout << "INFO::Constr. A Matrix with size (" << rows << ',' << columns
  //     << ")\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  // totalMemory();
}

// copy constructor
Matrix::Matrix(const Matrix &m) {
  _R = m._R;
  _C = m._C;
  _data = m._data;
  // cout << "INFO::Copy Constr. Copy a Matrix with size (" << _R << ',' << _C
  //     << ")\n";
  total_m = total_m + 2 * 4 + _data.size() * sizeof(_data[0]);
  // totalMemory();
}

// operator=
Matrix &Matrix::operator=(const Matrix &m) {
  // cout << "INFO::Custom operator '='. Copy a Matrix with size (" << m._R <<
  // ',' << m._C << ")\n";
  total_m = total_m - _data.size() * sizeof(_data[0]);

  _R = m._R;
  _C = m._C;
  _data = m._data;

  total_m = total_m + _data.size() * sizeof(_data[0]);
  // totalMemory();

  return (*this);
}

// operator+=
/*Matrix &Matrix::operator+=(const Matrix &m2) {
  if (_R != m2._R || _C != m2._C)
    throw std::logic_error("Matrix dimensions must agree.");
  for (int i = 0; i < _R * _C; i++) {
    _data[i] += m2._data[i];
  }
  return (*this);
}*/

Matrix &Matrix::operator+=(double x) {
  for (int i = 0; i < _R * _C; i++) {
    _data[i] += x;
  }
  return (*this);
}

// operator+
/*Matrix Matrix::operator+(const Matrix &m2) const {
  if (_R != m2._R || _C != m2._C)
    throw std::logic_error("Matrix dimensions must agree.");
  Matrix m(*this);
  m += m2;
  return (m);
}*/

Matrix Matrix::operator+(double x) const {
  Matrix m(*this);
  m += x;
  return (m);
}

// operator-=
/*Matrix &Matrix::operator-=(const Matrix &m2) {
  if (_R != m2._R || _C != m2._C)
    throw std::logic_error("Matrix dimensions must agree.");
  for (int i = 0; i < _R * _C; i++) {
    _data[i] -= m2._data[i];
  }
  return (*this);
}*/

Matrix &Matrix::operator-=(double x) {
  for (int i = 0; i < _R * _C; i++) {
    _data[i] -= x;
  }
  return (*this);
}

// operator-
/*Matrix Matrix::operator-(const Matrix &m2) const {
  if (_R != m2._R || _C != m2._C)
    throw std::logic_error("Matrix dimensions must agree.");
  Matrix m(*this);
  m -= m2;
  return (m);
}*/

Matrix Matrix::operator-(double x) const {
  Matrix m(*this);
  m -= x;
  return (m);
}

// operator*=
Matrix &Matrix::operator*=(double x) {
  for (int i = 0; i < _R * _C; i++) {
    _data[i] *= x;
  }
  return (*this);
}

// operator*
Matrix Matrix::operator*(double x) const {
  Matrix m(*this);
  m *= x;
  return (m);
}

// operator()
double Matrix::operator()(int r, int c) const {
  if (r > _R || c > _C)
    throw std::logic_error("Index exceeds array bounds");
  return (_data[c * _R + r]);
}

double &Matrix::operator()(int r, int c) {
  if (r > _R || c > _C)
    throw std::logic_error("Index exceeds array bounds");
  return (_data[c * _R + r]);
}

// Deconstructor
Matrix::~Matrix() {
  total_m = total_m - _data.size() * sizeof(_data[0]) - 2 * 4;
  // totalMemory();
}
void Matrix::resize(int rows, int columns) {
  if (rows * columns != _R * _C) {
    _R = rows;
    _C = columns;
    _data.resize(_R * _C);
    // std::cerr <<"Warning! Change the total memory of matrix.\n";
    return;
  }
  _R = rows;
  _C = columns;
}

double Matrix::get(int row, int column) const {
  if (row > _R || column > _C)
    throw std::logic_error("Index exceeds array bounds");
  int index = _R * column + row;
  return (_data[index]);
}

void Matrix::set(int row, int column, double x) {
  if (row > _R || column > _C)
    throw std::logic_error("Index exceeds array bounds");
  int index = _R * column + row;
  _data[index] = x;
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
void Matrix::transpose() {
  std::vector<double> t_data(_data); // a temp copy
  for (int i = 0; i < _C; i++)
    for (int j = 0; j < _R; j++)
      _data[j * _C + i] = t_data[i * _R + j];
  int temp;
  temp = _R;
  _R = _C;
  _C = temp;
}
void Matrix::identity(const int size) {
  if (size < 1)
    throw std::logic_error("size of matrix must >= 1");
  total_m = total_m - _data.size() * sizeof(_data[0]);
  _R = size;
  _C = size;
  _data.resize(_R * _C);
  std::fill(_data.begin(), _data.end(), 0);
  total_m = total_m + _data.size() * sizeof(_data[0]);
  for (int i = 0; i < size; i++)
    _data[_R * i + i] = 1;
}
void Matrix::chol(const char sign) {
  // if neither 'U' nor 'L', error
  int flag;
  if (sign == 'U' || sign == 'u')
    flag = 0;
  else if (sign == 'L' || sign == 'l')
    flag = 1;
  else
    throw std::logic_error("Error using chol. Option must be 'U' or 'L'.");
  if (_R != _C)
    throw std::logic_error("Error using chol. Matrix must be squre");
  std::vector<double> t_data(_data);

  _data.clear(); // lower part =0
  _data.resize(_R * _C);
  // loop
  double isPositive;
  for (int i = 0; i < _R; i++) {
    for (int j = 0; j <= i; j++) {
      double sum = 0;
      if (j == i) {
        for (int k = 0; k < j; k++)
          sum += pow(_data[j * _R + k], 2);
        isPositive = t_data[j * _R + j] - sum;
        if (isPositive <= 0)
          throw std::logic_error(
              "Error using chol. Matrix must be positive definite.");
        _data[j * _R + j] = sqrt(isPositive);
      } else {
        for (int k = 0; k < j; k++)
          sum += _data[i * _R + k] * _data[j * _R + k];
        _data[i * _R + j] = (t_data[i * _R + j] - sum) / _data[j * _R + j];
      }
    }
  }

  // check demand
  if (flag == 1)
    transpose();
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
  // totalMemory();
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
  // totalMemory();
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
/***********************************************************/
//developed based on OpenBLAS
void Matrix::isSymmProductOf(const Matrix & A, char TransA){
	//calculate size
	if (TransA == 'N'||TransA == 'n') //A*A'
	{
		_C = A._R;
		_R = A._R;
		_data.resize(_C * _R);
		f77blas_dgemm('N','T', A._R, A._R, A._C, 1.0, A._data.data(), A._R, A._data.data(), A._R, 0.0,_data.data(), _R);
	}
	else  //TransA == 'T', A'*A
	{
		_C = A._C;
		_R = A._C;
		_data.resize(_C * _R);
		f77blas_dgemm('T','N', A._C, A._C, A._R, 1.0, A._data.data(), A._R, A._data.data(), A._R, 0.0,_data.data(), _R);
	}		
	
}

void Matrix::plusSymmProductOf(const Matrix & A, char TransA, double w){
		if (TransA == 'N'||TransA == 'n') //A*A'
	{
		_C = A._R;
		_R = A._R;
		_data.resize(_C * _R);
		f77blas_dgemm('N','T', A._R, A._R, A._C, w, A._data.data(), A._R, A._data.data(), A._R, 1.0,_data.data(), _R);
	}
	else  //TransA == 'T', A'*A
	{
		_C = A._C;
		_R = A._C;
		_data.resize(_C * _R);
		f77blas_dgemm('T','N', A._C, A._C, A._R, w, A._data.data(), A._R, A._data.data(), A._R, 1.0,_data.data(), _R);
	}
}

void Matrix::isProductOf(const Matrix & A, const Matrix & B, char transA, char transB){
	int k;
	if (transA =='N' || transA == 'n')
	{	_R = A._R;
		k = A._C;
		}
	else {
		_R = A._C;
		k = A._R;
	}
	
	if (transB =='N' || transB == 'n')
		_C = B._C;
	else
		_C = B._R;
	
	_data.resize( _C * _R);
	
	f77blas_dgemm(transA, transB, _R, _C, k, 1.0, A._data.data(), A._R, B._data.data(), B._R, 0.0,_data.data(), _R);		
}
void Matrix::plusProductOf(const Matrix & A, const Matrix & B, char transA, char transB, double w){
	int k;
	if (transA =='N' || transA == 'n')
	{	_R = A._R;
		k = A._C;
		}
	else {
		_R = A._C;
		k = A._R;
	}
	
	if (transB =='N' || transB == 'n')
		_C = B._C;
	else
		_C = B._R;
	
	_data.resize( _C * _R);
	
	f77blas_dgemm(transA, transB, _R, _C, k, w, A._data.data(), A._R, B._data.data(), B._R, 1.0,_data.data(), _R);		
}

Matrix Matrix::operator*(const Matrix &A) const {
  Matrix m(_R, A._C); 
  m.isProductOf(*this, A, 'N','N');	
  return (m);
}

Matrix &Matrix::operator*=(const Matrix &A) {
  Matrix m(_R, A._C); 
  m.isProductOf(*this, A, 'N','N');	
  //(*this).plusProductOf(*this, A, 'N', 'N', 1.0);
  *this = m;
  return (*this);
}

  Matrix Matrix::operator+(const Matrix &A) const{
	  //check size
	  if ((A._C != _C) ||(A._R != _R))
		  throw std::logic_error("Matrix dimensions must agree.");
	  Matrix m;	  
	  m.identity(A._C); 
	  Matrix n(*this);
	  n.plusProductOf(A, m, 'N','N', 1.0);
	  return n;
	  
  }
  Matrix &Matrix::operator+=(const Matrix &A){
	  if ((A._C != _C) ||(A._R != _R))
		  throw std::logic_error("Matrix dimensions must agree.");
	  Matrix m;	  
	  m.identity(A._C); 
	  (*this).plusProductOf(A, m, 'N','N', 1.0);
	  return (*this);
  }
  Matrix Matrix::operator-(const Matrix &A) const{
	  //check size
	  if ((A._C != _C) ||(A._R != _R))
		  throw std::logic_error("Matrix dimensions must agree.");
	  Matrix m;	  
	  m.identity(A._C); 
	  Matrix n(*this);
	  n.plusProductOf(A, m, 'N','N', -1.0);
	  return n; 
  }
  Matrix &Matrix::operator-=(const Matrix &A){
	   if ((A._C != _C) ||(A._R != _R))
		  throw std::logic_error("Matrix dimensions must agree.");
	  Matrix m;	  
	  m.identity(A._C); 
	  (*this).plusProductOf(A, m, 'N','N', -1.0);
	  return (*this); 
  }




