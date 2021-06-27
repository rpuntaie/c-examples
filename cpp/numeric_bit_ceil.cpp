/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_bit_ceil.exe ./cpp/numeric_bit_ceil.cpp && (cd ../_build/cpp/;./numeric_bit_ceil.exe)
https://en.cppreference.com/w/cpp/numeric/bit_ceil
*/
#include <bit>
#include <bitset>
#include <iostream>
auto main() -> int
{
    using bin = std::bitset<8>;
    for (unsigned x{0}; x != 10; ++x)
    {
        auto const z = std::bit_ceil(x); // `ceil2` before P1956R1
        std::cout << "bit_ceil(" << bin(x) << ") = " << bin(z) << '\n';
    }
}

