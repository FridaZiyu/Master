//This is head file "myStatisticFunctions.hpp"
//developed by Ziyu Liu,Yu Dong 
//Date: 24/05/2020
#include <cmath>
#include <algorithm>
using namespace std;
//function declarations
//template <typename T>
double mean(const double* dataPtr , unsigned int len);
double median(const double* dataPtr , unsigned int len);
//T quantile(const T* dataPtr , unsigned int len, unsigned int p = 1); 
//double var(const T* dataPtr , unsigned int len);  //variance
//double std(const T* dataPtr , unsigned int len); //standard deviation

//function definitions
//template <typename T>
double mean(const double* dataPtr , unsigned int len){
	double m =0;
	for (unsigned int i=0; i<len;i++)
		m += dataPtr[i];
	return (m/len);
}

double median(const double* dataPtr , unsigned int len){
	//step1 sort
	double* copy =nullptr;
	copy = new double [len];
	for(unsigned int i=0;i<len;i++)
		copy[i]=dataPtr[i];
	std::sort(copy, copy+len);
	//get median
	double m =0;
	if (len%2==0)
		//when length of array is an even number
		m = (copy[len/2]+copy[len/2+1])/2;
		
	else
		//when length of array is an odd number
		m = copy[(len+1)/2];
	//delete copy
	delete[] copy;
	copy = nullptr;
	
	return  m;
}

