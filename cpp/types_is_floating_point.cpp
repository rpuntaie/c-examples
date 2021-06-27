/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_floating_point.exe ./cpp/types_is_floating_point.cpp && (cd ../_build/cpp/;./types_is_floating_point.exe)
https://en.cppreference.com/w/cpp/types/is_floating_point
*/
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_floating_point<A>::value << '\n';
    std::cout << std::is_floating_point<float>::value << '\n';
    std::cout << std::is_floating_point<float&>::value << '\n';
    std::cout << std::is_floating_point<double>::value << '\n';
    std::cout << std::is_floating_point<double&>::value << '\n';
    std::cout << std::is_floating_point<int>::value << '\n';
}

