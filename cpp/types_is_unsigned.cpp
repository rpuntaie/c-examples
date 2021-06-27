/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_unsigned.exe ./cpp/types_is_unsigned.cpp && (cd ../_build/cpp/;./types_is_unsigned.exe)
https://en.cppreference.com/w/cpp/types/is_unsigned
*/
#include <iostream>
#include <type_traits>
class A {};
enum B : unsigned {};
enum class C : unsigned {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_unsigned<A>::value << '\n';
    std::cout << std::is_unsigned<float>::value << '\n';
    std::cout << std::is_unsigned<signed int>::value << '\n';
    std::cout << std::is_unsigned<unsigned int>::value << '\n';
    std::cout << std::is_unsigned<B>::value << '\n';
    std::cout << std::is_unsigned<C>::value << '\n';
}

