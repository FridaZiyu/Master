#ifndef MATRIX_HPP_
#define MATRIX_HPP_
#include <iostream>
#include <string>
#include <vector>
class Matrix {
public:
  // constructor
  Matrix();
  Matrix(int rows, int columns);
  Matrix(int rows, int columns, const std::vector<double> &data);
  Matrix(const Matrix &m);
  ~Matrix(); // decon.
  // operators
  Matrix &operator=(const Matrix &m);
  Matrix operator+(const Matrix& anotherMatrix) const;
  Matrix operator+(double x) const;
  Matrix operator-(const Matrix& anotherMatrix) const;
  Matrix operator-(double x) const;
  Matrix operator*(double x) const;
  Matrix &operator+=(const Matrix& anotherMatrix);
  Matrix &operator+=(double x);
  Matrix &operator-=(const Matrix& anotherMatrix);
  Matrix &operator-=(double x);
  Matrix &operator*=(double x);
  double operator()(int r, int c) const;
  //void &operator()(int r, int c, double x);
  // member functions
  void resize(int rows, int columns);
  // get & set
  double get(int r, int c) const;
  void set(int r, int c, double x);
  // max & min
  double max() const;
  double min() const;
  double max(int &r, int &c) const;
  double min(int &r, int &c) const;
  // IO
  void AsciiRead(const std::string filename);
  void AsciiWrite(const std::string filename);
  void BinaryRead(const std::string filename);
  void BinaryWrite(const std::string filename);
  void print() const; // print
  // static func.
  static int totalMemory();
private:
  int _R = 0;
  int _C = 0;
  std::vector<double> _data;
  static int total_m; // monitor total memory
};
#endif
