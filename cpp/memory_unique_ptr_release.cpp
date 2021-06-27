/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_release.exe ./cpp/memory_unique_ptr_release.cpp && (cd ../_build/cpp/;./memory_unique_ptr_release.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/release
*/
#include <memory>
#include <iostream>
#include <cassert>
struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
};
int main()
{
    std::cout << "Creating new Foo...\n";
    std::unique_ptr<Foo> up(new Foo());
    std::cout << "About to release Foo...\n";
    Foo* fp = up.release();
    assert (up.get() == nullptr);
    assert (up == nullptr);
    std::cout << "Foo is no longer owned by unique_ptr...\n";
    delete fp;
}

