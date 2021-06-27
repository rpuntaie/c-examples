/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_destroy_at.exe ./cpp/memory_destroy_at.cpp && (cd ../_build/cpp/;./memory_destroy_at.exe)
https://en.cppreference.com/w/cpp/memory/destroy_at
*/
#include <memory>
#include <new>
#include <iostream>
struct Tracer {
    int value;
    ~Tracer() { std::cout << value << " destructed\n"; }
};
int main()
{
    alignas(Tracer) unsigned char buffer[sizeof(Tracer) * 8];
    for (int i = 0; i < 8; ++i)
        new(buffer + sizeof(Tracer) * i) Tracer{i}; //manually construct objects
    auto ptr = std::launder(reinterpret_cast<Tracer*>(buffer));
    for (int i = 0; i < 8; ++i)
        std::destroy_at(ptr + i);
}

