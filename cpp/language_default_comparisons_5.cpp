/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_default_comparisons_5.exe ./cpp/language_default_comparisons_5.cpp && (cd ../_build/cpp/;./language_default_comparisons_5.exe)
https://en.cppreference.com/w/cpp/language/default_comparisons
*/
#include <compare>
struct Point {
  int x;
  int y;
  auto operator<=>(const Point&) const = default;
  // ... non-comparison functions ...
};
// compiler generates all six two-way comparison operators
#include <iostream>
#include <set>
int main() {
  Point pt1{1, 1}, pt2{1, 2};
  std::set<Point> s; // ok
  s.insert(pt1);     // ok
  std::cout << std::boolalpha
    << (pt1 == pt2) << ' ' // false; operator== is implicitly defaulted.
    << (pt1 != pt2) << ' ' // true
    << (pt1 <  pt2) << ' ' // true
    << (pt1 <= pt2) << ' ' // true
    << (pt1 >  pt2) << ' ' // false
    << (pt1 >= pt2) << ' ';// false
}

