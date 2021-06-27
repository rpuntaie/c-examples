/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_transform_inclusive_scan.exe ./cpp/algorithm_transform_inclusive_scan.cpp && (cd ../_build/cpp/;./algorithm_transform_inclusive_scan.exe)
https://en.cppreference.com/w/cpp/algorithm/transform_inclusive_scan
*/
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
int main()
{
  std::vector data {3, 1, 4, 1, 5, 9, 2, 6};
  auto times_10 = [](int x) { return x * 10; };
  std::cout << "10 times exclusive sum: ";
  std::transform_exclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "),
                0, std::plus<int>{}, times_10);
  std::cout << "\n10 times inclusive sum: ";
  std::transform_inclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "),
                std::plus<int>{}, times_10);
}

