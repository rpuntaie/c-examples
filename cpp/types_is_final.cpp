/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_final.exe ./cpp/types_is_final.cpp && (cd ../_build/cpp/;./types_is_final.exe)
https://en.cppreference.com/w/cpp/types/is_final
*/
#include <iostream>
#include <type_traits>
class A {};
class B final {};
int main() 
{
    std::cout
        << std::boolalpha
        << std::is_final<A>::value << '\n'
        << std::is_final<B>::value << '\n';
}

