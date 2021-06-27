/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_offsetof.exe ./cpp/types_offsetof.cpp && (cd ../_build/cpp/;./types_offsetof.exe)
https://en.cppreference.com/w/cpp/types/offsetof
*/
#include <iostream>
#include <cstddef>
struct S {
    char   m0;
    double m1;
    short  m2;
    char   m3;
//  private: int z; // warning: 'S' is a non-standard-layout type
};
int main()
{
    std::cout
        << "offset of char   m0 = " << offsetof(S, m0) << '\n'
        << "offset of double m1 = " << offsetof(S, m1) << '\n'
        << "offset of short  m2 = " << offsetof(S, m2) << '\n'
        << "offset of char   m3 = " << offsetof(S, m3) << '\n';
}

