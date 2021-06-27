/*
g++ -std=c++20 -o ../_build/r/gp.exe r/gp.cpp && (cd ../_build/r;./gp.exe)
*/

#include <iostream>
#include <string>
#include <vector>
#include <ranges>
int main() {

  for (auto v: std::views::iota(1, 3'000))
    std::cout << v << " ";
  for (auto v : std::vector{1, 2, 3})
    std::cout << v << " ";
  for (auto vec = std::vector{1, 2, 3}; auto v : vec)
    std::cout << v << " ";

  std::cout << "\n\n";
  for (auto initList = {1, 2, 3}; auto e : initList) {
    e *= e;
    std::cout << e << " ";
  }
  std::cout << "\n\n";
  using namespace std::string_literals;
  for (auto str = "Hello World"s; auto c: str) {
    std::cout << c << " ";
  }
  std::cout << '\n';
}
