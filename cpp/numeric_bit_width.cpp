/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_bit_width.exe ./cpp/numeric_bit_width.cpp && (cd ../_build/cpp/;./numeric_bit_width.exe)
https://en.cppreference.com/w/cpp/numeric/bit_width
*/
#include <bit>
#include <bitset>
#include <iostream>
auto main() -> int
{
    for (unsigned x{0}; x != 8; ++x)
    {
        std::cout
            << "bit_width( "
            << std::bitset<4>{x} << " ) = "
            << std::bit_width(x) << '\n';
    }
}

