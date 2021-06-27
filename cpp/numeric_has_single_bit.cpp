/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_has_single_bit.exe ./cpp/numeric_has_single_bit.cpp && (cd ../_build/cpp/;./numeric_has_single_bit.exe)
https://en.cppreference.com/w/cpp/numeric/has_single_bit
*/
#include <bit>
#include <bitset>
#include <iostream>
int main()
{
    std::cout << std::boolalpha;
    for (auto i = 0u; i < 10u; ++i) {
        std::cout << "has_single_bit( " << std::bitset<4>(i) << " ) = "
                  << std::has_single_bit(i) // `ispow2` before P1956R1
                  << '\n';
    }
}

