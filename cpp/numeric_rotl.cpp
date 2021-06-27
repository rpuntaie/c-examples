/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_rotl.exe ./cpp/numeric_rotl.cpp && (cd ../_build/cpp/;./numeric_rotl.exe)
https://en.cppreference.com/w/cpp/numeric/rotl
*/
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
int main()
{
    std::uint8_t i = 0b00011101;
    std::cout << "i          = " << std::bitset<8>(i) << '\n';
    std::cout << "rotl(i,0)  = " << std::bitset<8>(std::rotl(i,0)) << '\n';
    std::cout << "rotl(i,1)  = " << std::bitset<8>(std::rotl(i,1)) << '\n';
    std::cout << "rotl(i,4)  = " << std::bitset<8>(std::rotl(i,4)) << '\n';
    std::cout << "rotl(i,9)  = " << std::bitset<8>(std::rotl(i,9)) << '\n';
    std::cout << "rotl(i,-1) = " << std::bitset<8>(std::rotl(i,-1)) << '\n';
}

