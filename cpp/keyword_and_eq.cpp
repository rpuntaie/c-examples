/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_and_eq.exe ./cpp/keyword_and_eq.cpp && (cd ../_build/cpp/;./keyword_and_eq.exe)
https://en.cppreference.com/w/cpp/keyword/and_eq
*/
#include <iostream>
#include <bitset>
int main()
{
    std::bitset<4> mask("1100");
    std::bitset<4> val("0111");
    val and_eq mask;
    std::cout << val << '\n';
}

