/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_cdata.exe ./cpp/ranges_cdata.cpp && (cd ../_build/cpp/;./ranges_cdata.exe)
https://en.cppreference.com/w/cpp/ranges/cdata
*/
#include <cstring>
#include <iostream>
#include <ranges>
#include <string>
int main()
{
    std::string src {"Hello world!\n"};
    char dst[20]; // storage for a C-style string
    std::strcpy(dst, std::ranges::cdata(src));
    // [data(src), data(src) + size(src)] is guaranteed to be an NTBS
    std::cout << dst;
}

