/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_17.exe ./cpp/language_pointer_17.cpp && (cd ../_build/cpp/;./language_pointer_17.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
#include <iostream>
struct Base
{
    void f(int n) { std::cout << n << '\n'; }
};
struct Derived : Base {};
int main()
{
    void (Base::* bp)(int) = &Base::f;
    void (Derived::* dp)(int) = bp;
    Derived d;
    (d.*dp)(1);
    (d.*bp)(2);
}

