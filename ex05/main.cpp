#include "myStatisticFunctions.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){	//is argc and argv neccessary?
  //create an array
  unsigned int size = 0;
  double *ptr = nullptr;
  //get the size of array
  cout << "Please input the length of array: \n";
  while (!(cin >> size) || size <= 0) {
    cerr << "Length should be a positive integer. \n";
    cin.clear();
    while (cin.get() != '\n')
      continue;
  }
  //input elements 
  ptr = new double[size];
  cout << "Please input " << size << " floating values of the array: " << endl;
  for (unsigned int i = 0; i < size; i++) {
    while (!(cin >> ptr[i])) {
      cerr << "Only number is acceptable.\n";
      cin.clear();
      while (cin.get() != '\n')
        continue;
    }
  }
  //print this array
  for (unsigned int i =0; i<size;i++)
	  cout<<i+1<<", "<<ptr[i]<<endl;
  
  //print statistic
  cout<<"------------------------------\n";
  
  //print the mean value
  cout<<"mean: "<<mean(ptr,size)<<endl;
  cout<<"median: "<<median(ptr,size)<<endl;
  cout<<"variance: "<<var(ptr,size)<<endl;
  cout<<"standard deviation: "<<stdDeviation(ptr,size)<<endl;
  //delete the array, free heap memory
  delete[] ptr;
  ptr = nullptr;
}