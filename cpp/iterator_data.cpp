/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_data.exe ./cpp/iterator_data.cpp && (cd ../_build/cpp/;./iterator_data.exe)
https://en.cppreference.com/w/cpp/iterator/data
*/
#include <string>
#include <cstring>
#include <iostream>
int main()
{
    std::string s {"Hello world!\n"};
    char a[20]; // storage for a C-style string
    std::strcpy(a, std::data(s));
    // [s.data(), s.data() + s.size()] is guaranteed to be an NTBS since C++11
    std::cout << a;
}

