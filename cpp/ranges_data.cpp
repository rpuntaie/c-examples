/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_data.exe ./cpp/ranges_data.cpp && (cd ../_build/cpp/;./ranges_data.exe)
https://en.cppreference.com/w/cpp/ranges/data
*/
#include <cstring>
#include <iostream>
#include <ranges>
#include <string>
int main()
{
    std::string s {"Hello world!\n"};
    char a[20]; // storage for a C-style string
    std::strcpy(a, std::ranges::data(s));
    // [data(s), data(s) + size(s)] is guaranteed to be an NTBS
    std::cout << a;
}

