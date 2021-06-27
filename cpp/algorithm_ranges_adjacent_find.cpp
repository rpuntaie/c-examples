/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_adjacent_find.exe ./cpp/algorithm_ranges_adjacent_find.cpp && (cd ../_build/cpp/;./algorithm_ranges_adjacent_find.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/adjacent_find
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
int main()
{
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};
    //                              ^^          ^^
    namespace ranges = std::ranges;
    auto i1 = ranges::adjacent_find(v1.begin(), v1.end());
    if (i1 == v1.end()) {
        std::cout << "No matching adjacent elements\n";
    } else {
        std::cout << "The first adjacent pair of equal elements is at ["
                  << ranges::distance(v1.begin(), i1) << "] == " << *i1 << '\n';
    }
    auto i2 = ranges::adjacent_find(v1, ranges::greater());
    if (i2 == v1.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    } else {
        std::cout << "The last element in the non-decreasing subsequence is at ["
                  << ranges::distance(v1.begin(), i2) << "] == " << *i2 << '\n';
    }
}

