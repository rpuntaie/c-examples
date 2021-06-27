/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_back_insert_iterator.exe ./cpp/iterator_back_insert_iterator.cpp && (cd ../_build/cpp/;./iterator_back_insert_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/back_insert_iterator
*/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
int main()
{
  std::vector<int> v;
  std::generate_n(
    std::back_insert_iterator<std::vector<int>>(v), // C++17: std::back_insert_iterator(v)
    10, [n=0]() mutable { return ++n; }             // or use std::back_inserter helper
  );
  for (int n : v)
    std::cout << n << ' ';
  std::cout << '\n';
}

