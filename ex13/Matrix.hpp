#ifndef MATRIX_HPP_
#define MATRIX_HPP_
#include "f77blas.h"
#include "f90lapack.h"
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
  Matrix operator+(double x) const;
  Matrix operator-(double x) const;
  Matrix operator*(double x) const;
  Matrix &operator+=(double x);
  Matrix &operator-=(double x);
  Matrix &operator*=(double x);
  double operator()(int r, int c) const;
  double &operator()(int r, int c);
  // member functions
  void resize(int rows, int columns);
  // get & set
  int rows() const { return _R; };
  int columns() const { return _C; };
  double get(int r, int c) const;
  void set(int r, int c, double x);
  // max & min
  double max() const;
  double min() const;
  double max(int &r, int &c) const;
  double min(int &r, int &c) const;
  // Algorithm
  void transpose();
  void identity(const int size); // generate size*size identity matrix(for test)
  void chol(const char sign = 'U'); // default same as Matlab
 
  // developed based on LAPACK
  void chol();
  void solveWithCholReduced(Matrix &R);
  void invCholReduced();
  // IO
  void AsciiRead(const std::string filename);
  void AsciiWrite(const std::string filename);
  void BinaryRead(const std::string filename);
  void BinaryWrite(const std::string filename);
  void print() const; // print
  // static func.
  static int totalMemory();

  // developed based on OpenBLAS
  void isSymmProductOf(const Matrix &A, char TransA);
  void plusSymmProductOf(const Matrix &A, char TransA, double w = 1.0);
  void isProductOf(const Matrix &A, const Matrix &B, char transA, char transB);
  void plusProductOf(const Matrix &A, const Matrix &B, char transA, char transB,
                     double w = 1.0);
  Matrix operator*(const Matrix &anotherMatrix) const;
  Matrix &operator*=(const Matrix &anotherMatrix);
  // additional
  Matrix operator+(const Matrix &anotherMatrix) const;
  Matrix &operator+=(const Matrix &anotherMatrix);
  Matrix operator-(const Matrix &anotherMatrix) const;
  Matrix &operator-=(const Matrix &anotherMatrix);

private:
  int _R = 0;
  int _C = 0;
  std::vector<double> _data;
  static int total_m; // monitor total memory
};
#endif
