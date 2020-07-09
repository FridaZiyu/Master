#include "Fourierseries.hpp"
#include <cmath>
#include <fstream>

using std::cout;
using std::string;

Fourierseries::Fourierseries(int n, double w) : _degree(n), _omega(w) {}
Fourierseries::Fourierseries(int n, double w, const Matrix coef)
    : _degree(n), _omega(w), _coef(coef) {}
Fourierseries::Fourierseries(const Fourierseries &f) {
  _degree = f._degree;
  _omega = f._omega;
  _coef = f._coef;
}

void Fourierseries::set_degree(int n) { _degree = n; }
void Fourierseries::set_freq(double w) { _omega = w; }

void Fourierseries::AsciiRead(const std::string filename) {}
void Fourierseries::AsciiWrite(const std::string filename) {}

void Fourierseries::getFunctionalValues(const Matrix &t, Matrix &l) {
  int n = _degree;
  int w = _omega;
  l.resize(t._R, 1);
  for (int i = 0; i < t._R; i++) {
    double s = _coef[0];
    for (int k = 1; k <= n; k++) {
      s += _coef[k] * cos(w * k * t._data[i]) +
           _coef[1 + 2 * k] * sin(w * k * t._data[i]);
    }
    l._data[i] = s;
  }
}
void Fourierseries::getDesignMatrix(const Matrix &t, Matrix &A) {
  A.resize(_degree * 2 + 1, t._R);
  int n = _degree;
  int w = _omega;
  for (int i = 0; i < t._R; i++) {
    A._data[i * 2 * n + 0] = 0.5;
    for (int k = 1; k <= n; k++) {
      if (k % 2 == 1)
        A._data[i * 2 * n + k] = cos(w * t._data[i]);
      else
        A._data[i * 2 * n + k] = sin(w * t._data[i]);
    }
  }
  A.transpose();
}
