#include "myStatisticFunctions.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // create an array
  unsigned int size = 0;
  vector<int> iVec;

  writeData(iVec, size);

  // input p (0-100)
  unsigned int p = 0;
  cout << "Please input p to calculate p%-quantile: " << endl;
  while (!(cin >> p) || p <= 0 || p > 100) {
    cerr << "p should be a value in range (0-100). \n";
    cin.clear();
    while (cin.get() != '\n')
      continue;
  }

  // print this array
  for (unsigned int i = 0; i < size; i++)
    cout << i + 1 << ", " << iVec[i] << endl;

  // print statistic
  cout << "------------------------------\n";

  // print the statistic result
  cout << "mean: " << mean(iVec, size) << endl;
  cout << "median: " << median(iVec, size) << endl;
  cout << "variance: " << var(iVec, size) << endl;
  cout << "standard deviation: " << stdDeviation(iVec, size) << endl;
  cout << p << "% quantile: " << quantile(iVec, size, p) << endl;
}
