/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_lexicographical_compare.exe ./cpp/algorithm_ranges_lexicographical_compare.cpp && (cd ../_build/cpp/;./algorithm_ranges_lexicographical_compare.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/lexicographical_compare
*/
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>
int main()
{
    std::vector<char> v1 {'a', 'b', 'c', 'd'};
    std::vector<char> v2 {'a', 'b', 'c', 'd'};
    namespace ranges = std::ranges;
    auto os = std::ostream_iterator<char>(std::cout, " ");
    std::mt19937 g{std::random_device{}()};
    while (!ranges::lexicographical_compare(v1, v2)) {
        ranges::copy(v1, os);
        std::cout << ">= ";
        ranges::copy(v2, os);
        std::cout << '\n';
        ranges::shuffle(v1, g);
        ranges::shuffle(v2, g);
    }
    ranges::copy(v1, os);
    std::cout << "<  ";
    ranges::copy(v2, os);
    std::cout << '\n';
}

