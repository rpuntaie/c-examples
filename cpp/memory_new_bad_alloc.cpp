/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_bad_alloc.exe ./cpp/memory_new_bad_alloc.cpp && (cd ../_build/cpp/;./memory_new_bad_alloc.exe)
https://en.cppreference.com/w/cpp/memory/new/bad_alloc
*/
#include <iostream>
#include <new>
int main()
{
    try {
        while (true) {
            new int[100000000ul];
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}

