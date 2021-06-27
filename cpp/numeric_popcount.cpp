/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_popcount.exe ./cpp/numeric_popcount.cpp && (cd ../_build/cpp/;./numeric_popcount.exe)
https://en.cppreference.com/w/cpp/numeric/popcount
*/
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
#include <iostream>
int main()
{
    for (std::uint8_t i : { 0, 0b11111111, 0b00011101 }) {
        std::cout << "popcount(0b" << std::bitset<8>(i) << ") = "
                  << std::popcount(i) << '\n';
    }
}

