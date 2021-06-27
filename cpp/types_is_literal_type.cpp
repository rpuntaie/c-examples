/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_literal_type.exe ./cpp/types_is_literal_type.cpp && (cd ../_build/cpp/;./types_is_literal_type.exe)
https://en.cppreference.com/w/cpp/types/is_literal_type
*/
#include <iostream>
#include <type_traits>
struct A {
    int m;
};
struct B {
    virtual ~B();
};
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<A>::value << '\n';
    std::cout << std::is_literal_type<B>::value << '\n';
}

