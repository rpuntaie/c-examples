/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_reference.exe ./cpp/types_is_reference.cpp && (cd ../_build/cpp/;./types_is_reference.exe)
https://en.cppreference.com/w/cpp/types/is_reference
*/
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_reference<A>::value << '\n';
    std::cout << std::is_reference<A&>::value << '\n';
    std::cout << std::is_reference<A&&>::value << '\n';
    std::cout << std::is_reference<int>::value << '\n';
    std::cout << std::is_reference<int&>::value << '\n';
    std::cout << std::is_reference<int&&>::value << '\n';
}

