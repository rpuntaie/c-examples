/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_pointer_interconvertible_with_class.exe ./cpp/types_is_pointer_interconvertible_with_class.cpp && (cd ../_build/cpp/;./types_is_pointer_interconvertible_with_class.exe)
https://en.cppreference.com/w/cpp/types/is_pointer_interconvertible_with_class
*/
#include <type_traits>
#include <iostream>
struct Foo { int x; };
struct Bar { int y; };
struct Baz : Foo, Bar {}; // not standard-layout
int main()
{
    std::cout << std::boolalpha
        << std::is_same_v<decltype(&Baz::x), int Baz::*>
        << std::is_pointer_interconvertible_with_class(&Baz::x) << '\n'
        << std::is_pointer_interconvertible_with_class<Baz>(&Baz::x) << '\n';
}

