/*
g++ --std=c++20 -pthread -o ../_build/cpp/preprocessor_conditional.exe ./cpp/preprocessor_conditional.cpp && (cd ../_build/cpp/;./preprocessor_conditional.exe)
https://en.cppreference.com/w/cpp/preprocessor/conditional
*/
#define ABCD 2
#include <iostream>
int main()
{
#ifdef ABCD
    std::cout << "1: yes\n";
#else
    std::cout << "1: no\n";
#endif
#ifndef ABCD
    std::cout << "2: no1\n";
#elif ABCD == 2
    std::cout << "2: yes\n";
#else
    std::cout << "2: no2\n";
#endif
#if !defined(DCBA) && (ABCD < 2*4-3)
    std::cout << "3: yes\n";
#endif
}

