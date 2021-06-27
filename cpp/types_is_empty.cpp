/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_empty.exe ./cpp/types_is_empty.cpp && (cd ../_build/cpp/;./types_is_empty.exe)
https://en.cppreference.com/w/cpp/types/is_empty
*/
#include <iostream>
#include <type_traits>
struct A {};
struct B {
    int m;
};
struct C {
    static int m;
};
struct D {
    virtual ~D();
};
union E {};
struct F {
    [[no_unique_address]] E e;
};
int main()
{
    std::cout << std::boolalpha;
    std::cout << "A " << std::is_empty<A>::value << '\n';
    std::cout << "B " << std::is_empty<B>::value << '\n';
    std::cout << "C " << std::is_empty<C>::value << '\n';
    std::cout << "D " << std::is_empty<D>::value << '\n';
    std::cout << "E " << std::is_empty<E>::value << '\n';
    std::cout << "F " << std::is_empty<F>::value << '\n'; // the result is ABI-dependent
}

