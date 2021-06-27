/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_transform.exe ./cpp/algorithm_ranges_transform.cpp && (cd ../_build/cpp/;./algorithm_ranges_transform.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/transform
*/
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::string s("hello");
    namespace ranges = std::ranges;
    ranges::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });
    std::vector<std::size_t> ordinals;
    ranges::transform(s, std::back_inserter(ordinals),
                      [](unsigned char c) -> std::size_t { return c; });
    std::cout << s << ':';
    for (auto ord : ordinals) {
       std::cout << ' ' << ord;
    }
    ranges::transform(ordinals, ordinals, ordinals.begin(), std::plus{});
    std::cout << '\n';
    for (auto ord : ordinals) {
       std::cout << ord << ' ';
    }
    std::cout << '\n';
}

