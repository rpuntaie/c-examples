/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_namespace_alias.exe ./cpp/language_namespace_alias.cpp && (cd ../_build/cpp/;./language_namespace_alias.exe)
https://en.cppreference.com/w/cpp/language/namespace_alias
*/
#include <iostream>
namespace foo {
    namespace bar {
         namespace baz {
             int qux = 42;
         }
    }
}
namespace fbz = foo::bar::baz;
int main()
{
    std::cout << fbz::qux << '\n';
}

