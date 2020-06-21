#pragma once
#include <iostream>
#include <vector>
#include <string>
class Matrix {
public:
  //constructor
  Matrix();
  Matrix(int rows, int columns);
  Matrix(int rows, int columns, const std::vector<double> &data);
  Matrix(const Matrix& m);   
  ~Matrix();  //decon.
  //modify
  Matrix& operator=(const Matrix& m);
  void resize(int rows, int columns);
  //get & set
  double get(int r, int c) const;
  void set(int r, int c, double x);
  //max & min
  double max() const;
  double min() const;
  double max(int &r, int &c) const;
  double min(int &r, int &c) const;  
  //IO
  void AsciiRead(const std::string filename);
  void AsciiWrite(const std::string filename)const;
  void BinaryRead(const std::string filename);
  void BinaryWrite(const std::string filename);
  void print() const;  //print
  //static func.
  static int totalMemory();

private:
  int _R = 0;
  int _C = 0;
  std::vector<double> _data;
  static int total_m; //monitor total memory
};


