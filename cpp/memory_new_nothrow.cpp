/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_nothrow.exe ./cpp/memory_new_nothrow.cpp && (cd ../_build/cpp/;./memory_new_nothrow.exe)
https://en.cppreference.com/w/cpp/memory/new/nothrow
*/
#include <iostream>
#include <new>
int main()
{
    try {
        while (true) {
            new int[100000000ul];   // throwing overload
        }
    } catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
    while (true) {
        int* p = new(std::nothrow) int[100000000ul]; // non-throwing overload
        if (p == nullptr) {
            std::cout << "Allocation returned nullptr\n";
            break;
        }
    }
}

