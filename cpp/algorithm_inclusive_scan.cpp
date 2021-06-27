/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_inclusive_scan.exe ./cpp/algorithm_inclusive_scan.cpp && (cd ../_build/cpp/;./algorithm_inclusive_scan.exe)
https://en.cppreference.com/w/cpp/algorithm/inclusive_scan
*/
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
int main()
{
  std::vector data {3, 1, 4, 1, 5, 9, 2, 6};
  std::cout << "exclusive sum: ";
  std::exclusive_scan(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, " "),
              0);
  std::cout << "\ninclusive sum: ";
  std::inclusive_scan(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n\nexclusive product: ";  
  std::exclusive_scan(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, " "),
              1, std::multiplies<>{});            
  std::cout << "\ninclusive product: ";
  std::inclusive_scan(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, " "),
              std::multiplies<>{});            
}

