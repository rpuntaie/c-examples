/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_base_of.exe ./cpp/types_is_base_of.cpp && (cd ../_build/cpp/;./types_is_base_of.exe)
https://en.cppreference.com/w/cpp/types/is_base_of
*/
#include <iostream>
#include <type_traits>
class A {};
class B : A {};
class C {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
    std::cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
    std::cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
    std::cout << "same type: " << std::is_base_of<C, C>::value << '\n';
}

