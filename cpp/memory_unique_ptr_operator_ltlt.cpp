/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_operator_ltlt.exe ./cpp/memory_unique_ptr_operator_ltlt.cpp && (cd ../_build/cpp/;./memory_unique_ptr_operator_ltlt.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/operator_ltlt
*/
#include <iostream>
#include <memory>
class Foo {};
int main()
{
    auto p = std::make_unique<Foo>();
    std::cout << p << '\n';
    std::cout << p.get() << '\n';
}

