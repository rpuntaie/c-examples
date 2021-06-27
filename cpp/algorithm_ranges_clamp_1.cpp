/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_clamp_1.exe ./cpp/algorithm_ranges_clamp_1.cpp && (cd ../_build/cpp/;./algorithm_ranges_clamp_1.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/clamp
*/
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std::literals;
int main()
{
    std::cout << " raw   clamped to int8_t   clamped to uint8_t\n";
    for(int const v: {-129, -128, -1, 0, 42, 127, 128, 255, 256}) {
        std::cout << std::setw(04) << v
                  << std::setw(20) << std::ranges::clamp(v, INT8_MIN, INT8_MAX)
                  << std::setw(21) << std::ranges::clamp(v, 0, UINT8_MAX) << '\n';
    }
    std::cout << '\n';
    // Projection function
    const auto stoi = [](std::string s) { return std::stoi(s); };
    // Same as above, but with strings
    for(std::string const v: {"-129", "-128", "-1", "0", "42", "127", "128", "255", "256"}) {
        std::cout << std::setw(04) << v
                  << std::setw(20) << std::ranges::clamp(v, "-128"s, "127"s, {}, stoi)
                  << std::setw(21) << std::ranges::clamp(v, "0"s, "255"s, {}, stoi) << '\n';
    }
}

