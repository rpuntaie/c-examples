/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_countr_zero.exe ./cpp/numeric_countr_zero.cpp && (cd ../_build/cpp/;./numeric_countr_zero.exe)
https://en.cppreference.com/w/cpp/numeric/countr_zero
*/
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
#include <iostream>
int main()
{
    for (std::uint8_t i : { 0, 0b11111111, 0b00011100 }) {
        std::cout << "countr_zero(0b" << std::bitset<8>(i) << ") = "
                  << std::countr_zero(i) << '\n';
    }
}

