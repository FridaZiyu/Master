#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
// using namespace std;

template <typename T> void print(const T &begin, const T &end);
bool IsNeg(double x);
bool compare(double a, double b);

int main() {
  double f[] = {1.1, 1.2, 1.2, 1.5, 0.4, 0.1, -4.3, 0.1, -1.3};
  std::vector<double> v;
  unsigned int len = sizeof(f) / sizeof(f[0]);
  // 1) copy
  std::vector<double> cp;
  cp.resize(len);
  std::copy(f, f + len, cp.begin());
  // 2) Sort f ascending
  std::sort(f, f + len);
  // 3) median
  int n = len / 2;
  if (len % 2 == 1)
    std::cout << "median: " << f[n] << '\n';
  else
    std::cout << "median: " << (f[n - 1] + f[n]) / 2.0 << '\n';

  // 4) mean
  double sum = std::accumulate(cp.cbegin(), cp.cend(), (double)0.0);
  if (std::fabs(sum) <= std::numeric_limits<double>::epsilon())
    sum = 0;
  double mean = sum / len;
  std::cout << "mean: " << mean << '\n';
  // 5) standard deviation
  double var = std::accumulate(
      cp.cbegin(), cp.cend(), (double)0.0,
      [mean](double a, double d) { return a + std::pow(d - mean, 2); });
  std::cout << "standard deviation: " << std::sqrt(var) << '\n';

  // 6) insert unique_copy
  std::unique_copy(f, f + len, std::back_inserter(v));

  // 7) print v
  std::cout << "v";
  print(v.cbegin(), v.cend());

  // 8) print v descending
  std::sort(v.begin(), v.end());
  std::cout << "v descending";
  print(v.rbegin(), v.rend());

  // 9) recover
  std::copy(cp.begin(), cp.begin() + len, f);

  // 10) print original sequence
  std::cout << "original f = [ ";
  std::copy(f, f + len, std::ostream_iterator<double>(std::cout, " "));
  std::cout << "]" << std::endl;

  // 11) replace all negative numbers with 9.9
  std::replace_if(f, f + len, IsNeg, 9.9);
  std::cout << "f without negative numbers = [ ";
  std::copy(f, f + len, std::ostream_iterator<double>(std::cout, " "));
  std::cout << "]" << std::endl;

  // 12) the difference of neighbor elements
  std::vector<double> diff(len);
  std::adjacent_difference(f, f + len, diff.begin());
  std::cout << "slope";
  print(diff.begin() + 1, diff.end());

  // 13) count negative, positive and zero slope
  int negative = std::count_if(diff.cbegin() + 1, diff.cend(), IsNeg);
  int zero = std::count(diff.cbegin() + 1, diff.cend(), 0.0);
  int positive =
      std::distance(diff.cbegin() + 1, diff.cend()) - negative - zero;
  std::cout << "there are " << negative << " slopes are negative, " << positive
            << " slopes are positive and " << zero << " slopes are zero.\n";

  // 14) find the largest slope
  auto max_abs_slope = std::max_element(diff.cbegin(), diff.cend(), compare);
  auto loc = std::distance(diff.cbegin(), max_abs_slope);
  std::cout << "the largest slope " << *max_abs_slope << " is between "
            << f[loc - 1] << " and " << f[loc] << '\n';
  return 0;
}

template <typename T> void print(const T &begin, const T &end) {
  std::cout << " = [ ";
  std::copy(begin, end, std::ostream_iterator<double>(std::cout, " "));
  std::cout << "]" << '\n';
}

bool IsNeg(double x) { return (x < 0.0); }
bool compare(double a, double b) { return (std::fabs(a) < std::fabs(b)); }
