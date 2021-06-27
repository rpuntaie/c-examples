/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_unique.exe ./cpp/container_list_unique.cpp && (cd ../_build/cpp/;./container_list_unique.exe)
https://en.cppreference.com/w/cpp/container/list/unique
*/
#include <iostream>
#include <list>
auto print = [](auto remark, auto const& container) {
  std::cout << remark;
  for (auto const& val : container)
    std::cout << ' ' << val;
  std::cout << '\n';
};
int main()
{
  std::list<int> c = {1, 2, 2, 3, 3, 2, 1, 1, 2};
  print("Before unique():", c);
  c.unique();
  print("After  unique():", c);
  c = {1, 2, 12, 23, 3, 2, 51, 1, 2};
  print("Before unique(pred):", c);
  c.unique([mod=10](int x, int y) { return (x % mod) == (y % mod); });
  print("After  unique(pred):", c);
}

