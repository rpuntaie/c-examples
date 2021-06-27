/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_class.exe ./cpp/types_is_class.cpp && (cd ../_build/cpp/;./types_is_class.exe)
https://en.cppreference.com/w/cpp/types/is_class
*/
#include <iostream>
#include <type_traits>
struct A {};
class B {};
enum class C {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_class<A>::value << '\n';
    std::cout << std::is_class<B>::value << '\n';
    std::cout << std::is_class<C>::value << '\n';
    std::cout << std::is_class<int>::value << '\n';
}

