//This is head file "myStatisticFunctions.hpp"
//developed by Ziyu Liu,Yu Dong 
//Date: 24/05/2020
#include <cmath>
#include <algorithm>
using namespace std;
//function declarations
template <typename T> double mean(const T* dataPtr ,const unsigned int& len);
template <typename T> double median(const T* dataPtr ,const unsigned int& len);
//variance type: 1) sample variance; 2) population variance
template <typename T> 
double var(const T* dataPtr ,const unsigned int& len, const unsigned int type =1); 
//standard deviation type: 1) sample; 2) population 
template <typename T> 
double stdDeviation(const T* dataPtr ,const unsigned int& len,  const unsigned int type =1); 
//template <typename T> 
//double quantile(const T* dataPtr , unsigned int len,const unsigned int p = 25);  // p%-quantile

//function definitions
template <typename T>
double mean(const T* dataPtr ,const unsigned int& len){
	double m =0;
	for (unsigned int i=0; i<len;i++)
		m += dataPtr[i];
	return (m/len);
}
template <typename T>
double median(const T* dataPtr ,const unsigned int& len){
	//step1 sort
	T* copy =nullptr;
	copy = new T [len];
	for(unsigned int i=0;i<len;i++)
		copy[i]=dataPtr[i];
	std::sort(copy, copy+len);
	//get median
	double m =0;
	if (len%2==0)
		//when length of array is an even number
		m = (copy[len/2-1]+copy[len/2])/2;
		
	else
		//when length of array is an odd number
		m = copy[(len-1)/2];
	//delete copy
	delete[] copy;
	copy = nullptr;
	
	return  m;
}
template <typename T>
double var(const T* dataPtr ,const unsigned int& len, const unsigned int type){
	double m = mean(dataPtr, len);
	double sum;
	for (int i=0;i<len;i++)
		sum+=pow(dataPtr[i]-m,2);
	
	if (type ==1)
		sum = sum/(len-1);
	else
		sum = sum/len;
	return sum;
}

template <typename T> 
double stdDeviation(const T* dataPtr ,const unsigned int& len, const unsigned int type){
	double p = var(dataPtr, len, type);
	return sqrt(p);
}


