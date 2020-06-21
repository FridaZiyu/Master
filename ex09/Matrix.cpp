#include "Matrix.hpp"
#include <algorithm>
#include <vector>
#include <stream>
#include <fstream>
using std::cout;
using std::string;
Matrix::Matrix(){
	total_m = total_m + _data.size();
	cout<< "creat empty matrix\n";
	totalMemory();
}
Matrix::Matrix(int rows, int columns) : _R(rows), _C(columns) {
  //cout << "INFO::Constr. 'Matrix::Matrix(rows,columns)'\n";
  _data.resize(_R * _C);
  std::fill(_data.begin(), _data.end(), 0);
  total_m = total_m + _data.size();
  totalMemory();
}

Matrix::Matrix(int rows, int columns, const std::vector<double> &data)
    : _R(rows), _C(columns), _data(data) {
  //cout << "INFO::Constr. 'Matrix::Matrix(rows,columns,data)'\n";
  total_m = total_m + _data.size();
	totalMemory();
}

//copy constructor
Matrix::Matrix(const Matrix& m){
	_R = m._R;
	_C = m._C;
	_data = m._data;
	total_m = total_m + _data.size();
	totalMemory();
}
// '=' operator
Matrix& Matrix::operator=(const Matrix& m){
	cout << "INFO:: Custom operator '=' is using\n";
	total_m = total_m - _data.size();
	
	_R = m._R;
	_C = m._C;
	_data = m._data;
	
	total_m = total_m + _data.size();
	totalMemory();
	
	return (*this);
}

//Deconstructor
Matrix::~Matrix(){
	total_m = total_m - _data.size();
	totalMemory();
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

double Matrix::max(int &r, int &c) const{
  auto maximum = std::max_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), maximum);
  r = loc % _R;
  c = loc / _R;
  return (*maximum);
}
double Matrix::min(int &r, int &c) const{
  auto minimum = std::min_element(_data.begin(), _data.end());
  auto loc = std::distance(_data.begin(), minimum);
  r = loc % _R;
  c = loc / _R;
  return (*minimum);
}
//IO
void Matrix::AsciiRead(const string filename){
	//calculate total_m
	
}
void Matrix::AsciiWrite(const string filename)const{
	
}
void Matrix::BinaryRead(const string filename){
	//calculate total_m
	
}
void Matrix::BinaryWrite(const string filename)const{
	
}
void Matrix::print() const{  
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
int Matrix::totalMemory(){
	cout<< "Current memory usage: " << total_m << " Byte\n";
	return total_m;
}

