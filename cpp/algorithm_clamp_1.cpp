/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_clamp_1.exe ./cpp/algorithm_clamp_1.cpp && (cd ../_build/cpp/;./algorithm_clamp_1.exe)
https://en.cppreference.com/w/cpp/algorithm/clamp
*/
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
int main()
{
    std::cout << " raw   clamped to int8_t   clamped to uint8_t\n";
    for(int const v: {-129, -128, -1, 0, 42, 127, 128, 255, 256}) {
        std::cout << std::setw(04) << v
                  << std::setw(20) << std::clamp(v, INT8_MIN, INT8_MAX)
                  << std::setw(21) << std::clamp(v, 0, UINT8_MAX) << '\n';
    }
}

