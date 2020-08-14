#ifndef OPENBLAS_F77BLAS_H
#define OPENBLAS_F77BLAS_H
#define f77blas_daxpy daxpy_
#define f77blas_dgemm dgemm_ 
//#define f77blas_dsyrk dsyrk_
#define f77blas_dtrsm dtrsm_
#define f77blas_dpotrf dpotrf_
extern "C" {
void f77blas_daxpy( const int &n, const double &alpha, const double *x, const int &incx, double *y, const int &incy );
void f77blas_dgemm( const char &transA, const char &transB,const int &M,const int &N,const int &K,const double &alpha,const double *A,const int &ldA,const double *B,const int &ldB, const double &beta, double *C,const int &ldC);
//void f77blas_dsyrk( const char &uplo, const char &trans, const int &n, const int &k, const double &alpha,const double *A, const int &ldA, const double &beta, double *C, const int &ldC);
void f77blas_dtrsm( const char &side, const char &uplo, const char &transA, const char &diag, const int &M, const int &N, const double &alpha, double *A, const int &ldA, double *B, const int &ldB);  
//LAPACK
void f77blas_dpotrf( const char &UL, const int &N, double *A, const int &ldA, int &info);  //Cholesky factorization
}
#endif