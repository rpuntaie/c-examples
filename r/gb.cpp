/*
g++ -std=c++20 -o ../_build/r/gb.exe r/gb.cpp && (cd ../_build/r;./gb.exe)
*/

#include <iostream>
#include <bitset>
#include <bit>
#include <algorithm>

int main() {
    std::uint8_t num= 0b10110010;
    std::cout << std::has_single_bit(num) << '\n';
    // false
    std::cout << std::bit_width(unsigned(5)) << '\n';
    // 3
    std::cout << std::bitset<8>(std::rotl(num, 2)) << '\n';
    // 11001010
    std::cout << std::bitset<8>(std::rotr(num, 2)) << '\n';
    // 10101100

    int x = -3;
    unsigned int y = 7;
    if (x < y) std::cout << "expected";
    else std::cout << "not expected";
    // not expected
    if (std::cmp_less(x, y)) std::cout << "expected";
    // expected
    else std::cout << "not expected";
}
