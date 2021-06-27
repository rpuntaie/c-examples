/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_bit_cast_1.exe ./cpp/numeric_bit_cast_1.cpp && (cd ../_build/cpp/;./numeric_bit_cast_1.exe)
https://en.cppreference.com/w/cpp/numeric/bit_cast
*/
#include <cstdint>
#include <bit>
#include <iostream>
constexpr double f64v = 19880124.0;
constexpr auto u64v = std::bit_cast<std::uint64_t>(f64v);
constexpr std::uint64_t u64v2 = 0x3fe9000000000000ull;
constexpr auto f64v2 = std::bit_cast<double>(u64v2);
int main()
{
    std::cout
        << std::fixed <<f64v << "f64.to_bits() == 0x"
        << std::hex << u64v << "u64\n";
    std::cout
        << "f64::from_bits(0x" << std::hex << u64v2 << "u64) == "
        << std::fixed << f64v2 << "f64\n";
}

