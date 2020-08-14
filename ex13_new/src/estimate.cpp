#include "Matrix.hpp"
#include "Fourierseries.hpp"
int main(){
	//Read neccessary files
	Matrix CP, Coef, Simu, Set;
	CP.AsciiRead("txt/ControlPoints.txt");
	Coef.AsciiRead("txt/FourierCoefficients.txt");
	Simu.AsciiRead("txt/SimulatedObservation.txt");
	Set.AsciiRead("txt/Setting.txt");
	//B: SimulatedObservation, AX = B
	//get DesignMatrix A
	double w = Set(0,0);
	int num = (Coef.rows()-1)/2;
	Fourierseries Fourier( num, w);
	Matrix A;
	Fourier.getDesignMatrix( CP, A);	
	
	Matrix N, n, R;
	N.isSymmProductOf( A, 'T');	
	n.isProductOf( A, Simu, 'T', 'N');	
	R = N;	
	R.chol();
	
	//get parameter X
	Matrix x;
	x = n;
	x.solveWithCholReduced( R );
	x.print();
	
	Matrix Est;
	Est = A * x;	
	
	//get residual v, variance factor
	Matrix Res = Est - Simu;
	//determine the covariance of the parameters D(X)
	Matrix Var(R);
	Var.invCholReduced( );
	
	Matrix Sigma;
	Sigma.isProductOf( Res, Res, 'T', 'N');
	Sigma(0,0) = Sigma(0,0)/ (CP.rows() - x.rows());
	//save in file:  parameters, covariance matrix, variance factor,
    //the adjusted observations and the residuals 
	x.AsciiWrite("txt/EstimateCoef.txt");
	Var.AsciiWrite("txt/covariance.txt");
	Sigma.AsciiWrite("txt/VarianceFactor.txt");
	Est.AsciiWrite("txt/EstimateObservation.txt");
	Res.AsciiWrite("txt/Residual.txt");
	return 0;
}