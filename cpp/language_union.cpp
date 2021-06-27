/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_union.exe ./cpp/language_union.cpp && (cd ../_build/cpp/;./language_union.exe)
https://en.cppreference.com/w/cpp/language/union
*/
#include <iostream>
#include <cstdint>
union S
{
    std::int32_t n;     // occupies 4 bytes
    std::uint16_t s[2]; // occupies 4 bytes
    std::uint8_t c;     // occupies 1 byte
};                      // the whole union occupies 4 bytes
int main()
{
    S s = {0x12345678}; // initializes the first member, s.n is now the active member
    // at this point, reading from s.s or s.c is undefined behavior
    std::cout << std::hex << "s.n = " << s.n << '\n';
    s.s[0] = 0x0011; // s.s is now the active member
    // at this point, reading from n or c is UB but most compilers define it
    std::cout << "s.c is now " << +s.c << '\n' // 11 or 00, depending on platform
              << "s.n is now " << s.n << '\n'; // 12340011 or 00115678
}

