#include "myStatisticFunctions.hpp"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) { 
  // create a std::vector
  unsigned int size = 0;
  vector<int> iVec;
  // get the size of vector
  cout << "Please input the length of vector: \n";
  while (!(cin >> size) || size <= 0) {
    cerr << "Length should be a positive integer. \n";
    cin.clear();
    while (cin.get() != '\n')
      continue;
  }
  // input elements
  iVec.resize(size);
  cout << "Please input " << size << " integral values of the vector: " << endl;
  for (unsigned int i = 0; i < size; i++) {
    while (!(cin >> iVec[i])) {
      cerr << "Only number is acceptable.\n";
      cin.clear();
      while (cin.get() != '\n')
        continue;
    }
  }
  // input p (0-100)
  unsigned int p = 0;
  cout << "Please input p to calculate p%-quantile: " << endl;
  while (!(cin >> p) || p <= 0) {
    cerr << "p should be a positive integer. \n";
    cin.clear();
    while (cin.get() != '\n')
      continue;
  }

  // print this vector
  for (unsigned int i = 0; i < size; i++)
    cout << i + 1 << ", " << iVec[i] << endl;

  // print statistic
  cout << "------------------------------\n";

  // print the mean value
  cout << "mean: " << mean(iVec, size) << endl;
  cout << "median: " << median(iVec, size) << endl;
  cout << "variance: " << var(iVec, size) << endl;
  cout << "standard deviation: " << stdDeviation(iVec, size) << endl;
  cout << p << "% quantile: " << quantile(iVec, size, p) << endl;

  return 0;
}
