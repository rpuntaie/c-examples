/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_clog.exe ./cpp/io_clog.cpp && (cd ../_build/cpp/;./io_clog.exe)
https://en.cppreference.com/w/cpp/io/clog
*/
#include <iostream>
struct Foo {
    int n;
    Foo() {
       std::clog << "static constructor\n";
    }
    ~Foo() {
       std::clog << "static destructor\n";
    }
};
Foo f; // static object
int main()
{
    std::clog << "main function\n";
}

