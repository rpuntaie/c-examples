/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_bit_floor.exe ./cpp/numeric_bit_floor.cpp && (cd ../_build/cpp/;./numeric_bit_floor.exe)
https://en.cppreference.com/w/cpp/numeric/bit_floor
*/
#include <bit>
#include <bitset>
#include <iostream>
auto main() -> int
{
    using bin = std::bitset<8>;
    for (unsigned x = 0; x != 10; ++x)
    {
        auto const z = std::bit_floor(x); // `floor2` before P1956R1
        std::cout << "bit_floor(" << bin(x) << ") = " << bin(z) << '\n';
    }
}

