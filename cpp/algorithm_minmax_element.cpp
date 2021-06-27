/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_minmax_element.exe ./cpp/algorithm_minmax_element.cpp && (cd ../_build/cpp/;./algorithm_minmax_element.exe)
https://en.cppreference.com/w/cpp/algorithm/minmax_element
*/
#include <algorithm>
#include <iostream>
int main() {
    const auto v = { 3, 9, 1, 4, 2, 5, 9 };
    const auto [min, max] = std::minmax_element(begin(v), end(v));
    std::cout << "min = " << *min << ", max = " << *max << '\n';
}

