/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_destructible.exe ./cpp/types_is_destructible.cpp && (cd ../_build/cpp/;./types_is_destructible.exe)
https://en.cppreference.com/w/cpp/types/is_destructible
*/
#include <iostream>
#include <string>
#include <type_traits>
struct Foo {
   std::string str;
   ~Foo() noexcept {};
};
struct Bar {
    ~Bar() = default;
};
int main() {
    std::cout << std::boolalpha
              << "std::string is destructible? "
              << std::is_destructible<std::string>::value << '\n'
              << "Foo is trivially destructible? "
              << std::is_trivially_destructible_v<Foo> << '\n'
              << "Foo is nothrow destructible? "
              << std::is_nothrow_destructible<Foo>() << '\n'
              << "Bar is trivially destructible? "
              << std::is_trivially_destructible<Bar>{} << '\n';
}

