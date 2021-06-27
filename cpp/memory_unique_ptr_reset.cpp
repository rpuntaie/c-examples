/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_reset.exe ./cpp/memory_unique_ptr_reset.cpp && (cd ../_build/cpp/;./memory_unique_ptr_reset.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/reset
*/
#include <iostream>
#include <memory>
struct Foo { // object to manage
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};
struct D { // deleter
    void operator() (Foo* p) {
        std::cout << "Calling delete for Foo object... \n";
        delete p;
    }
};
int main()
{
    std::cout << "Creating new Foo...\n";
    std::unique_ptr<Foo, D> up(new Foo(), D());  // up owns the Foo pointer (deleter D)
    std::cout << "Replace owned Foo with a new Foo...\n";
    up.reset(new Foo());  // calls deleter for the old one
    std::cout << "Release and delete the owned Foo...\n";
    up.reset(nullptr);      
}

