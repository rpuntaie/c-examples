/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_fundamental.exe ./cpp/types_is_fundamental.cpp && (cd ../_build/cpp/;./types_is_fundamental.exe)
https://en.cppreference.com/w/cpp/types/is_fundamental
*/
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << "A\t"      << std::is_fundamental<A>::value << '\n';
    std::cout << "int\t"    << std::is_fundamental<int>::value << '\n';
    std::cout << "int&\t"   << std::is_fundamental<int&>::value << '\n';
    std::cout << "int*\t"   << std::is_fundamental<int*>::value << '\n';
    std::cout << "float\t"  << std::is_fundamental<float>::value << '\n';
    std::cout << "float&\t" << std::is_fundamental<float&>::value << '\n';
    std::cout << "float*\t" << std::is_fundamental<float*>::value << '\n';
}

