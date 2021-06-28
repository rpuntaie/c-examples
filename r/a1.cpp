/*
g++ -std=c++20 -o ../_build/r/a1.exe r/a1.cpp && (cd ../_build/r;./a1.exe)
*/
// all_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::all_of
#include <array>        // std::array

int main() {
  std::array<int,8> foo = {3,5,7,11,13,17,19,23};

  //any_of
  //none_of
  if ( std::all_of(foo.begin(), foo.end(), [](int i){return i%2;}) )
    std::cout << "All the elements are odd numbers.\n";

  return 0;
}
