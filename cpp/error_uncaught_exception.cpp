/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_uncaught_exception.exe ./cpp/error_uncaught_exception.cpp && (cd ../_build/cpp/;./error_uncaught_exception.exe)
https://en.cppreference.com/w/cpp/error/uncaught_exception
*/
#include <iostream>
#include <exception>
#include <stdexcept>
struct Foo {
    int count = std::uncaught_exceptions();
    ~Foo() {
        std::cout << (count == std::uncaught_exceptions()
            ? "~Foo() called normally\n"
            : "~Foo() called during stack unwinding\n");
    }
};
int main()
{
    Foo f;
    try {
        Foo f;
        std::cout << "Exception thrown\n";
        throw std::runtime_error("test exception");
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
}

