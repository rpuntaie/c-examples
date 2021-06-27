/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_byte.exe ./cpp/types_byte.cpp && (cd ../_build/cpp/;./types_byte.exe)
https://en.cppreference.com/w/cpp/types/byte
*/
#include <iostream>
#include <cstddef>
int main()
{
    std::byte b{42};
    std::cout << std::to_integer<int>(b) << "\n";
    // b *= 2 compilation error
    b <<= 1;
    std::cout << std::to_integer<int>(b) << "\n";
}

