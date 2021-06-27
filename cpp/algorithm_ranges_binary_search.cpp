/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_binary_search.exe ./cpp/algorithm_ranges_binary_search.cpp && (cd ../_build/cpp/;./algorithm_ranges_binary_search.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/binary_search
*/
#include <algorithm>
#include <iostream>
int main()
{
    constexpr static auto haystack = {1, 3, 4, 5, 9};
    constexpr static auto needles = {1, 2, 3};
    for (auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';
        if (std::ranges::binary_search(haystack, needle)) {
            std::cout << "Found " << needle << '\n';
        } else {
            std::cout << "no dice!\n";
        }
    }
}

