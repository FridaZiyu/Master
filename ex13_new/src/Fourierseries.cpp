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

void Fourierseries::getFunctionalValues(const Matrix &t, Matrix &l) {
  int n = _degree;
  double w = _omega;
  l.resize(t.rows(), 1);
  for (int i = 0; i < t.rows(); i++) {
    double s = _coef(0, 0) / 2;
    for (int k = 1; k <= n; k++) {
      s += _coef(2 * k - 1, 0) * cos(w * k * t(i, 0)) +
           _coef(2 * k, 0) * sin(w * k * t(i, 0));
    }
    l(i, 0) = s;
  }
}
void Fourierseries::getDesignMatrix(const Matrix &t, Matrix &A) {
  A.resize(_degree * 2 + 1, t.rows());
  int n = _degree;
  double w = _omega;
  for (int i = 0; i < t.rows(); i++) {
    A(0, i) = 0.5;
    for (int k = 1; k <= n; k++) {
      A(2 * k - 1, i) = cos(w * k * t(i, 0));
      A(2 * k, i) = sin(w * k * t(i, 0));
    }
  }
  A.transpose();
}
