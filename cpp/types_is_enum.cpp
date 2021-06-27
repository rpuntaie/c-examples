/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_enum.exe ./cpp/types_is_enum.cpp && (cd ../_build/cpp/;./types_is_enum.exe)
https://en.cppreference.com/w/cpp/types/is_enum
*/
#include <iostream>
#include <type_traits>
class A {};
enum E {};
enum class Ec : int {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_enum<A>::value << '\n';
    std::cout << std::is_enum<E>::value << '\n';
    std::cout << std::is_enum_v<int> << '\n'; // Uses helper variable template (C++17)
    std::cout << std::is_enum_v<Ec> << '\n'; // Uses helper variable template (C++17)
}

