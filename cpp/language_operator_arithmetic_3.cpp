/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_arithmetic_3.exe ./cpp/language_operator_arithmetic_3.cpp && (cd ../_build/cpp/;./language_operator_arithmetic_3.exe)
https://en.cppreference.com/w/cpp/language/operator_arithmetic
*/
#include <iostream>
#include <iomanip>
#include <bitset>
int main()
{
    uint16_t mask = 0x00f0;
    uint32_t x0 = 0x12345678;
    uint32_t x1 = x0 | mask;
    uint32_t x2 = x0 & ~mask;
    uint32_t x3 = x0 & mask;
    uint32_t x4 = x0 ^ mask;
    uint32_t x5 = ~x0;
    using bin16 = std::bitset<16>;
    using bin32 = std::bitset<32>;
    std::cout << std::hex << std::showbase
              << "Mask: " << mask << std::setw(49) << bin16(mask) << '\n'
              << "Value: " << x0 << std::setw(42) << bin32(x0) << '\n'
              << "Setting bits: " << x1 << std::setw(35) << bin32(x1) << '\n'
              << "Clearing bits: " << x2 << std::setw(34) << bin32(x2) << '\n'
              << "Selecting bits: " << x3 << std::setw(39) << bin32(x3) << '\n'
              << "XOR-ing bits: " << x4 << std::setw(35) << bin32(x4) << '\n'
              << "Inverting bits: " << x5 << std::setw(33) << bin32(x5) << '\n';
}

