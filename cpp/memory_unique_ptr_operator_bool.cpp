/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_operator_bool.exe ./cpp/memory_unique_ptr_operator_bool.cpp && (cd ../_build/cpp/;./memory_unique_ptr_operator_bool.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/operator_bool
*/
#include <iostream>
#include <memory>
int main()
{
    std::unique_ptr<int> ptr(new int(42));
    if (ptr) std::cout << "before reset, ptr is: " << *ptr << '\n';
    ptr.reset();
    if (ptr) std::cout << "after reset, ptr is: " << *ptr << '\n';
}

