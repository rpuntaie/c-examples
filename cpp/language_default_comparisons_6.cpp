/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_default_comparisons_6.exe ./cpp/language_default_comparisons_6.cpp && (cd ../_build/cpp/;./language_default_comparisons_6.exe)
https://en.cppreference.com/w/cpp/language/default_comparisons
*/
struct Point {
  int x;
  int y;
  bool operator==(const Point&) const = default;
  // ... non-comparison functions ...
};
// compiler generates element-wise equality testing
#include <iostream>
int main() {
  Point pt1{3, 5}, pt2{2, 5};
  std::cout << std::boolalpha
    << (pt1 != pt2) << '\n'  // true
    << (pt1 == pt1) << '\n'; // true
  struct [[maybe_unused]] { int x{}, y{}; } p, q;
  // if (p == q) { } // Error: 'operator==' is not defined
}

