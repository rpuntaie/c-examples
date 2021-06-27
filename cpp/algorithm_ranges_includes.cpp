/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_includes.exe ./cpp/algorithm_ranges_includes.cpp && (cd ../_build/cpp/;./algorithm_ranges_includes.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/includes
*/
#include <iostream>
#include <algorithm>
#include <cctype>
template <class Os, class R> Os& operator<<(Os& os, const R& r) {
  for (const auto& e : r) os << e << ' ';
  return os << '\t';
}
int main()
{
  const auto
    v1 = {'a', 'b', 'c', 'f', 'h', 'x'},
    v2 = {'a', 'b', 'c'},
    v3 = {'a', 'c'},
    v4 = {'a', 'a', 'b'},
    v5 = {'g'},
    v6 = {'a', 'c', 'g'},
    v7 = {'A', 'B', 'C'};
  auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };
  namespace ranges = std::ranges;
  std::cout
    << v1 << "\nincludes:\n" << std::boolalpha
    << v2 << ": " << ranges::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n'
    << v3 << ": " << ranges::includes(v1, v3) << '\n'
    << v4 << ": " << ranges::includes(v1, v4) << '\n'
    << v5 << ": " << ranges::includes(v1, v5) << '\n'
    << v6 << ": " << ranges::includes(v1, v6) << '\n'
    << v7 << ": " << ranges::includes(v1, v7, no_case)
          << " (case-insensitive)\n";
}

