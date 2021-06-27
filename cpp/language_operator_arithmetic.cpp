/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_arithmetic.exe ./cpp/language_operator_arithmetic.cpp && (cd ../_build/cpp/;./language_operator_arithmetic.exe)
https://en.cppreference.com/w/cpp/language/operator_arithmetic
*/
#include <iostream>
int main()
{
    char c = 0x6a;
    int n1 = 1;
    unsigned char n2 = 1;
    unsigned int n3 = 1;
    std::cout << "char: " << c << " int: " << +c << '\n'
              << "-1, where 1 is signed: " << -n1 << '\n'
              << "-1, where 1 is unsigned char: " << -n2 << '\n'
              << "-1, where 1 is unsigned int: " << -n3 << '\n';
    char a[3];
    std::cout << "size of array: " << sizeof a << '\n'
              << "size of pointer: " << sizeof +a << '\n';
}

