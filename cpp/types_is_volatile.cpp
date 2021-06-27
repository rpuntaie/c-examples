/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_volatile.exe ./cpp/types_is_volatile.cpp && (cd ../_build/cpp/;./types_is_volatile.exe)
https://en.cppreference.com/w/cpp/types/is_volatile
*/
#include <iostream>
#include <type_traits>
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_volatile<int>::value << '\n';
    std::cout << std::is_volatile<volatile int>::value  << '\n';
}

