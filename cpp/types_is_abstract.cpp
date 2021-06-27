/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_abstract.exe ./cpp/types_is_abstract.cpp && (cd ../_build/cpp/;./types_is_abstract.exe)
https://en.cppreference.com/w/cpp/types/is_abstract
*/
#include <iostream>
#include <type_traits>
struct A {
    int m;
};
struct B {
    virtual void foo();
};
struct C {
    virtual void foo() = 0;
};
struct D : C {};
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_abstract<A>::value << '\n';
    std::cout << std::is_abstract<B>::value << '\n';
    std::cout << std::is_abstract<C>::value << '\n';
    std::cout << std::is_abstract<D>::value << '\n';
}

