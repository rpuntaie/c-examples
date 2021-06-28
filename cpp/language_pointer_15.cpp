/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_15.exe ./cpp/language_pointer_15.cpp && (cd ../_build/cpp/;./language_pointer_15.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
#include <iostream>
struct A
{
    int m;
    // const pointer to non-const member
    int A::* const p;
};
int main()
{
    // non-const pointer to data member which is a const pointer to non-const member
    int A::* const A::* p1 = &A::p;
    const A a = {1, &A::m};
    std::cout << a.*(a.*p1) << '\n'; // prints 1
    // regular non-const pointer to a const pointer-to-member
    int A::* const* p2 = &a.p;
    std::cout << a.**p2 << '\n'; // prints 1
}

