/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_bad_typeid.exe ./cpp/types_bad_typeid.cpp && (cd ../_build/cpp/;./types_bad_typeid.exe)
https://en.cppreference.com/w/cpp/types/bad_typeid
*/
#include <iostream>
#include <typeinfo>
struct S { // The type has to be polymorphic
    virtual void f();
}; 
int main()
{
    S* p = nullptr;
    try {
        std::cout << typeid(*p).name() << '\n';
    } catch(const std::bad_typeid& e) {
        std::cout << e.what() << '\n';
    }
}

