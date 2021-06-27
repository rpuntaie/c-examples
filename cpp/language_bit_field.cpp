/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_bit_field.exe ./cpp/language_bit_field.cpp && (cd ../_build/cpp/;./language_bit_field.exe)
https://en.cppreference.com/w/cpp/language/bit_field
*/
#include <iostream>
struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;
};
int main()
{
    S s = {6};
    ++s.b; // store the value 7 in the bit field
    std::cout << s.b << '\n';
    ++s.b; // the value 8 does not fit in this bit field
    std::cout << s.b << '\n'; // formally implementation-defined, typically 0
}

