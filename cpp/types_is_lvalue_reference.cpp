/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_lvalue_reference.exe ./cpp/types_is_lvalue_reference.cpp && (cd ../_build/cpp/;./types_is_lvalue_reference.exe)
https://en.cppreference.com/w/cpp/types/is_lvalue_reference
*/
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_lvalue_reference<A>::value << '\n';
    std::cout << std::is_lvalue_reference<A&>::value << '\n';
    std::cout << std::is_lvalue_reference<A&&>::value << '\n';
    std::cout << std::is_lvalue_reference<int>::value << '\n';
    std::cout << std::is_lvalue_reference<int&>::value << '\n';
    std::cout << std::is_lvalue_reference<int&&>::value << '\n';
}

