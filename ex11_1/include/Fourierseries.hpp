#ifndef FOUR_HPP_
#define FOUR_HPP_
#include "Matrix.hpp"
#include <string>
class Fourierseries{
public:
	// constructor
	Fourierseries(){};
	Fourierseries(int n, double w);
	Fourierseries(int n, double w,const Matrix coef);
	Fourierseries(const Fourierseries &f);
	~Fourierseries(){};  //deconstructor	

	//get&set
	int get_degree() const {return _degree;} ;
	double get_freq() const {return _omega;} ;
	void set_degree(int n);
	void set_freq(double w);
	//IO
//	void AsciiRead(const std::string filename);
//	void AsciiWrite(const std::string filename);
	
	//further implementation
	void getFunctionalValues( const Matrix & t, Matrix & l );
	void getDesignMatrix( const Matrix & t,Matrix & A );
private:
	int _degree; //n_max
	double _omega; //base frequency
	Matrix _coef; //coefficients,size-> (2*n+1,1)
	
};
#endif