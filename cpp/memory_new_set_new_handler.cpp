/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_set_new_handler.exe ./cpp/memory_new_set_new_handler.cpp && (cd ../_build/cpp/;./memory_new_set_new_handler.exe)
https://en.cppreference.com/w/cpp/memory/new/set_new_handler
*/
#include <iostream>
#include <new>
void handler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
}
int main()
{
    std::set_new_handler(handler);
    try {
        while (true) {
            new int[100000000ul];
        }
    } catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
}

