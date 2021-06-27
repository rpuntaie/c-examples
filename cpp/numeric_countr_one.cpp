/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_countr_one.exe ./cpp/numeric_countr_one.cpp && (cd ../_build/cpp/;./numeric_countr_one.exe)
https://en.cppreference.com/w/cpp/numeric/countr_one
*/
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
#include <iostream>
int main()
{
    for (std::uint8_t i : { 0, 0b11111111, 0b11100011 }) {
        std::cout << "countr_one(0b" << std::bitset<8>(i) << ") = "
                  << std::countr_one(i) << '\n';
    }
}

