/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_trivial.exe ./cpp/types_is_trivial.cpp && (cd ../_build/cpp/;./types_is_trivial.exe)
https://en.cppreference.com/w/cpp/types/is_trivial
*/
#include <iostream>
#include <type_traits>
struct A {
    int m;
};
struct B {
    B() {}
};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_trivial<A>::value << '\n';
    std::cout << std::is_trivial<B>::value << '\n';
}

