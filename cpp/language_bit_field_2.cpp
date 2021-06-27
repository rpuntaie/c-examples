/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_bit_field_2.exe ./cpp/language_bit_field_2.cpp && (cd ../_build/cpp/;./language_bit_field_2.exe)
https://en.cppreference.com/w/cpp/language/bit_field
*/
#include <iostream>
struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte
    unsigned char b2 : 6;
    unsigned char b3 : 2;
};
int main()
{
    std::cout << sizeof(S) << '\n'; // usually prints 2
}

