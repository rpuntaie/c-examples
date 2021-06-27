/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_end.exe ./cpp/container_set_end.cpp && (cd ../_build/cpp/;./container_set_end.exe)
https://en.cppreference.com/w/cpp/container/set/end
*/
#include <algorithm>
#include <iostream>
#include <set>
int main() {
  std::set<int> set = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
  std::for_each(set.cbegin(), set.cend(), [](int x) {
    std::cout << x << ' ';
  });
  std::cout << '\n';
}

