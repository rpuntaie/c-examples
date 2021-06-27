/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_function_1.exe ./cpp/types_is_function_1.cpp && (cd ../_build/cpp/;./types_is_function_1.exe)
https://en.cppreference.com/w/cpp/types/is_function
*/
#include <iostream>
#include <type_traits>
struct A {
    int fun() const&;
};
template<typename>
struct PM_traits {};
template<class T, class U>
struct PM_traits<U T::*> {
    using member_type = U;
};
int f();
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_function<A>::value << '\n';
    std::cout << std::is_function<int(int)>::value << '\n';
    std::cout << std::is_function<decltype(f)>::value << '\n';
    std::cout << std::is_function<int>::value << '\n';
    using T = PM_traits<decltype(&A::fun)>::member_type; // T is int() const&
    std::cout << std::is_function<T>::value << '\n';
}

