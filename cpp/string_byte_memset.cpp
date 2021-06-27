/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_memset.exe ./cpp/string_byte_memset.cpp && (cd ../_build/cpp/;./string_byte_memset.exe)
https://en.cppreference.com/w/cpp/string/byte/memset
*/
#include <iostream>
#include <cstring>
int main()
{
    int a[20];
    std::memset(a, 0, sizeof a);
    for (int ai : a) std::cout << ai;
}

