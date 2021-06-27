/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_operator.exe ./cpp/memory_unique_ptr_operator.cpp && (cd ../_build/cpp/;./memory_unique_ptr_operator.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/operator*
*/
#include <iostream>
#include <memory>
struct Foo {
    void bar() { std::cout << "Foo::bar\n"; }
};
void f(const Foo& foo) 
{
    std::cout << "f(const Foo&)\n";
}
int main() 
{
    std::unique_ptr<Foo> ptr(new Foo);
    ptr->bar();
    f(*ptr);
}

