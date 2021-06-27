/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_add_cv_1.exe ./cpp/types_add_cv_1.cpp && (cd ../_build/cpp/;./types_add_cv_1.exe)
https://en.cppreference.com/w/cpp/types/add_cv
*/
#include <iostream>
#include <type_traits>
struct foo
{
    void m() { std::cout << "Non-cv\n"; }
    void m() const { std::cout << "Const\n"; }
    void m() volatile { std::cout << "Volatile\n"; }
    void m() const volatile { std::cout << "Const-volatile\n"; }
};
int main()
{
    foo{}.m();
    std::add_const<foo>::type{}.m();
    std::add_volatile<foo>::type{}.m();
    std::add_cv<foo>::type{}.m();
}

