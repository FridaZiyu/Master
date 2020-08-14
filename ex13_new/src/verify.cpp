#include "Matrix.hpp"
#include <iostream>
using std::cout;
int main(){
	Matrix Diff;
	Matrix TrueCoef, EstCoef;
	TrueCoef.AsciiRead("txt/FourierCoefficients.txt");
	EstCoef.AsciiRead("txt/EstimateCoef.txt");
	Diff = TrueCoef - EstCoef;
	cout<<"-------------------------------------------------\n";
	cout<<"Difference between true and estimated parameters:\n";
	Diff.print();	
	cout<<"-------------------------------------------------\n";
	Matrix TrueObserv, EstObserv;
	TrueObserv.AsciiRead("txt/TrueObservation.txt");
	EstObserv.AsciiRead("txt/EstimateObservation.txt");
	Diff = TrueObserv - EstObserv;
	cout<<"Difference between true and estimated Observation:\n";
	Diff.print();
	cout<<"--------------------------------------------------\n";	
	Matrix Set,VarFactor;
	VarFactor.AsciiRead("txt/VarianceFactor.txt");
	Set.AsciiRead("txt/Setting.txt");
	cout<<"---------------------------\n";
	cout<< " Variance0:" << Set( 1, 0) << std::endl;
	cout<< " Estimated Var:" << VarFactor( 0, 0) << std::endl;
	cout<<"---------------------------\n";
	return 0;
}