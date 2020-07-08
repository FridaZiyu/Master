#include "Fourierseries.hpp"
#include <fstream>

using std::cout;
using std::string;

Fourierseries::Fourierseries(int n, double w):_degree(n),_omega(w){}
Fourierseries::Fourierseries(int n, double w,const Matrix coef):_degree(n),_omega(w),_coef(coef){}
Fourierseries::Fourierseries(const Fourierseries &f){
	_degree = f._degree;
	_omega = f._omega;
	_coef = f._coef;
}

void Fourierseries::set_degree(int n){
	_degree = n;
}
void Fourierseries::set_freq(double w){
	_omega = w;
}

void Fourierseries::AsciiRead(const std::string filename){}
void Fourierseries::AsciiWrite(const std::string filename){}

void Fourierseries::getFunctionalValues( const Matrix & t, Matrix & l ){
	
}
void Fourierseries::getDesignMatrix( const Matrix & t,Matrix & A ){
	
}
