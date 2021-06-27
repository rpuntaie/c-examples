/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_union.exe ./cpp/types_is_union.cpp && (cd ../_build/cpp/;./types_is_union.exe)
https://en.cppreference.com/w/cpp/types/is_union
*/
#include <iostream>
#include <type_traits>
struct A {};
typedef union {
    int a;
    float b;
} B;
struct C {
    B d;
};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_union<A>::value << '\n';
    std::cout << std::is_union<B>::value << '\n';
    std::cout << std::is_union<C>::value << '\n';
    std::cout << std::is_union<int>::value << '\n';
}

