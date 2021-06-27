/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_array.exe ./cpp/types_is_array.cpp && (cd ../_build/cpp/;./types_is_array.exe)
https://en.cppreference.com/w/cpp/types/is_array
*/
#include <array>
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_array<A>::value << '\n';
    std::cout << std::is_array<A[]>::value << '\n';
    std::cout << std::is_array<A[3]>::value << '\n';
    std::cout << std::is_array<float>::value << '\n';
    std::cout << std::is_array<int>::value << '\n';
    std::cout << std::is_array<int[]>::value << '\n';
    std::cout << std::is_array<int[3]>::value << '\n';
    std::cout << std::is_array<std::array<int, 3>>::value << '\n';
}

