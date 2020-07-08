#pragma once
#include <chrono>
class TicToc {
public:
 void tic() { start_ = std::chrono::steady_clock::now(); }

 double toc() {
   auto end = std::chrono::steady_clock::now();
  // calculate duration
  std::chrono::duration<double> diff = end - start_;
  return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
 }

private:
 std::chrono::time_point<std::chrono::steady_clock> start_;
};
