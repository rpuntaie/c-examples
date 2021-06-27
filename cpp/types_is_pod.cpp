/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_pod.exe ./cpp/types_is_pod.cpp && (cd ../_build/cpp/;./types_is_pod.exe)
https://en.cppreference.com/w/cpp/types/is_pod
*/
#include <iostream>
#include <type_traits>
struct A {
    int m;
};
struct B {
    int m1;
private:
    int m2;
};
struct C {
    virtual void foo();
};
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_pod<A>::value << '\n';
    std::cout << std::is_pod<B>::value << '\n';
    std::cout << std::is_pod<C>::value << '\n';
}

