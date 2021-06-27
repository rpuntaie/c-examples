/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_type_info_name.exe ./cpp/types_type_info_name.cpp && (cd ../_build/cpp/;./types_type_info_name.exe)
https://en.cppreference.com/w/cpp/types/type_info/name
*/
#include <iostream>
#include <typeinfo>
struct Base { virtual ~Base() = default; };
struct Derived : Base {};
int main() {
    Base b1;
    Derived d1;
    const Base *pb = &b1;
    std::cout << typeid(*pb).name() << '\n';
    pb = &d1;
    std::cout << typeid(*pb).name() << '\n';
}

