/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_is_sorted.exe ./cpp/algorithm_is_sorted.cpp && (cd ../_build/cpp/;./algorithm_is_sorted.exe)
https://en.cppreference.com/w/cpp/algorithm/is_sorted
*/
#include <iostream>
#include <algorithm>
#include <iterator>
int main() 
{
    int digits[] = {3, 1, 4, 1, 5};
    for (auto i : digits) std::cout << i << ' ';
    std::cout << ": is_sorted: " << std::boolalpha
              << std::is_sorted(std::begin(digits), std::end(digits)) << '\n';
    std::sort(std::begin(digits), std::end(digits));
    for (auto i : digits) std::cout << i << ' ';
    std::cout << ": is_sorted: "
              << std::is_sorted(std::begin(digits), std::end(digits)) << '\n';
}

