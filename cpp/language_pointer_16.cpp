/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_16.exe ./cpp/language_pointer_16.cpp && (cd ../_build/cpp/;./language_pointer_16.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
#include <iostream>
struct C
{
    void f(int n) { std::cout << n << '\n'; }
};
int main()
{
    void (C::* p)(int) = &C::f; // pointer to member function f of class C
    C c;
    (c.*p)(1);                  // prints 1
    C* cp = &c;
    (cp->*p)(2);                // prints 2
}

