/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_trivially_copyable.exe ./cpp/types_is_trivially_copyable.cpp && (cd ../_build/cpp/;./types_is_trivially_copyable.exe)
https://en.cppreference.com/w/cpp/types/is_trivially_copyable
*/
#include <iostream>
#include <type_traits>
struct A {
    int m;
};
struct B {
    B(B const&) {}
};
struct C {
    virtual void foo();
};
struct D {
    int m;
    D(D const&) = default; // -> trivially copyable
    D(int x): m(x+1) {}
};
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_trivially_copyable<A>::value << '\n';
    std::cout << std::is_trivially_copyable<B>::value << '\n';
    std::cout << std::is_trivially_copyable<C>::value << '\n';
    std::cout << std::is_trivially_copyable<D>::value << '\n';
}

