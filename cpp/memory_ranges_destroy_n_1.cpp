/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_destroy_n_1.exe ./cpp/memory_ranges_destroy_n_1.cpp && (cd ../_build/cpp/;./memory_ranges_destroy_n_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/destroy_n
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
    std::ranges::destroy_n(ptr, 8);
}

