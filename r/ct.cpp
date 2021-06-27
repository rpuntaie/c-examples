/*
g++ -std=c++20 -o ../_build/r/ct.exe r/ct.cpp && (cd ../_build/r;./ct.exe)
*/
#include <iostream>
#include <vector>
#include <chrono>
int main() {
  std::vector<int> myBigVec(10000000, 2011);
  std::vector<int> myEmptyVec1;
  auto begin= std::chrono::high_resolution_clock::now();
  myEmptyVec1 = myBigVec;
  auto end= std::chrono::high_resolution_clock::now() - begin;
  auto timeInSeconds = std::chrono::duration<double>(end).count();
  std::cout << timeInSeconds << std::endl;
  return 0;
}
