/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_operator_ltlt.exe ./cpp/memory_shared_ptr_operator_ltlt.cpp && (cd ../_build/cpp/;./memory_shared_ptr_operator_ltlt.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/operator_ltlt
*/
#include <iostream>
#include <memory>
class Foo {};
int main()
{
    auto sp = std::make_shared<Foo>();
    std::cout << sp << '\n';
    std::cout << sp.get() << '\n';
}

