/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_hash.exe ./cpp/memory_unique_ptr_hash.cpp && (cd ../_build/cpp/;./memory_unique_ptr_hash.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/hash
*/
#include <iostream>
#include <memory>
#include <functional>
struct Foo {
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};
int main()
{
    Foo* foo = new Foo();
    std::unique_ptr<Foo> up(foo);
    std::cout << "hash(up):  " << std::hash<std::unique_ptr<Foo>>()(up) << '\n';
    std::cout << "hash(foo): " << std::hash<Foo*>()(foo) << '\n';
}

