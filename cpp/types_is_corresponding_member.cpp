/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_corresponding_member.exe ./cpp/types_is_corresponding_member.cpp && (cd ../_build/cpp/;./types_is_corresponding_member.exe)
https://en.cppreference.com/w/cpp/types/is_corresponding_member
*/
#include <type_traits>
#include <iostream>
struct Foo { int x; };
struct Bar { int y; double z; };
struct Baz : Foo, Bar {}; // not standard-layout
int main()
{
    std::cout << std::boolalpha
        << std::is_same_v<decltype(&Baz::x), int Foo::*> << '\n'
        << std::is_same_v<decltype(&Baz::y), int Bar::*> << '\n'
        << std::is_corresponding_member(&Foo::x, &Bar::y) << '\n'
        << std::is_corresponding_member(&Baz::x, &Baz::y) << '\n'
        << std::is_corresponding_member<Baz, Baz>(&Baz::x, &Baz::y) << '\n';
}

