/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_fill.exe ./cpp/algorithm_ranges_fill.cpp && (cd ../_build/cpp/;./algorithm_ranges_fill.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/fill
*/
#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    namespace ranges = std::ranges;
    ranges::fill(v.begin(), v.end(), -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    ranges::fill(v, 10);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

