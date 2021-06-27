/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_conditional.exe ./cpp/types_conditional.cpp && (cd ../_build/cpp/;./types_conditional.exe)
https://en.cppreference.com/w/cpp/types/conditional
*/
#include <iostream>
#include <type_traits>
#include <typeinfo>
int main() 
{
    typedef std::conditional<true, int, double>::type Type1;
    typedef std::conditional<false, int, double>::type Type2;
    typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
    std::cout << typeid(Type1).name() << '\n';
    std::cout << typeid(Type2).name() << '\n';
    std::cout << typeid(Type3).name() << '\n';
}

