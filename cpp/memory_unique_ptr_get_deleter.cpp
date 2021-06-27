/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_get_deleter.exe ./cpp/memory_unique_ptr_get_deleter.cpp && (cd ../_build/cpp/;./memory_unique_ptr_get_deleter.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/get_deleter
*/
#include <iostream>
#include <memory>
struct Foo
{
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};
struct D
{
    void bar() { std::cout << "Call deleter D::bar()...\n"; }
    void operator()(Foo* p) const
    {
        std::cout << "Call delete for Foo object...\n";
        delete p;
    }
};
int main()
{
    std::unique_ptr<Foo, D> up(new Foo(), D());
    D& del = up.get_deleter();
    del.bar();
}

