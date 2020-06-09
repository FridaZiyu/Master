#include <algorithm>
//#include <array>
#include "myStatisticFunctions.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

bool IsNeg(double x);
void print(const vector<double>::iterator &begin,
           const vector<double>::iterator &end);

int main() {
  vector<double> f = {1.1, 1.2, 1.2, 1.5, 0.4, 0.1, -4.3, 0.1, -1.3};
  // array<double,9> f = {1.1,1.2,1.2,1.5,0.4,0.1,-4.3,0.1,-1.3};
  vector<double> v;
  auto cp(f);
  sort(cp.begin(), cp.end());
  cout << "f in ascending = ";
  print(cp.begin(), cp.end());
  cout << "mean: " << mean(f, 9) << endl;
  cout << "median: " << median(f, 9) << endl;
  cout << "standard deviation: " << stdDeviation(f, 9) << endl;
  v.resize(9);
  v.resize(unique_copy(f.begin(), f.end(), v.begin()) -
           v.begin()); // unique copy and erase the redundant location
  // cout << "v = [  ";
  // copy(v.begin(), v.end(), ostream_iterator<double>(cout, "  "));
  // cout << "] " << endl;
  // sort(v.begin(), v.end());
  // cout << "v in descending = [  ";
  // copy(v.rbegin(), v.rend(), ostream_iterator<double>(cout, "  "));
  // cout << "] " << endl;
  // cout << "original f = [  ";
  // copy(f.begin(), f.end(), ostream_iterator<double>(cout, "  "));
  // cout << "] " << endl;
  // replace_if (f.begin(), f.end(), IsNeg, 9.9);
  // cout << "f without negative values = [  ";
  // copy(f.begin(), f.end(), ostream_iterator<double>(cout, "  "));
  // cout << "] " << endl;

  cout << "v = ";
  print(v.begin(), v.end());
  sort(v.begin(), v.end());
  // cout << "v in descending = ";
  // print(v.rbegin(), v.rend());//how to solve this problem?
  cout << "v in descending = [  ";
  copy(v.rbegin(), v.rend(), ostream_iterator<double>(cout, "  "));
  cout << "] " << endl;
  cout << "original f = ";
  print(f.begin(), f.end());
  replace_if(f.begin(), f.end(), IsNeg, 9.9);
  cout << "f without negative values = ";
  print(f.begin(), f.end());
  vector<double> diff;
  diff.resize(9);
  adjacent_difference(f.begin(), f.end(), diff.begin());
  cout << "the difference of neighboring elements are: " << endl;
  print(diff.begin() + 1, diff.end());
  // how to count the negative,positive and 0 without implementing a single
  // loop??
  // for find the largest slope, we'd better use minmax to find the max element,then find the pairs??
  vector<double>::iterator xItr;
  int neg = 0;
  int pos = 0;
  int zero = 0;
  vector<double>::iterator max = f.begin() + 1;
  for (xItr = diff.begin() + 1; xItr != diff.end(); ++xItr) {
    if (*xItr < 0)
      neg++;
    else if (*xItr > 0)
      pos++;
    else
      zero++;
    if (abs(*xItr) > abs(*max))
      max = xItr;
  }
  cout << pos << " slopes are positive, " << neg << " slopes are negative and "
       << zero << " slopes are zero." << endl;
  int loc = max - diff.begin();
  cout << "The largest slope " << *max << " is between "
       << *(f.begin() + loc - 1) << " and " << *(f.begin() + loc) << endl;

  return 0;
}

bool IsNeg(double x) { return (x < 0); }

void print(const vector<double>::iterator &begin,
           const vector<double>::iterator &end) {
  cout << "[  ";
  copy(begin, end, ostream_iterator<double>(cout, "  "));
  cout << "] " << endl;
}
