/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_uninitialized_fill_n_1.exe ./cpp/memory_uninitialized_fill_n_1.cpp && (cd ../_build/cpp/;./memory_uninitialized_fill_n_1.exe)
https://en.cppreference.com/w/cpp/memory/uninitialized_fill_n
*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>
int main()
{
    std::string* p;
    std::size_t sz;
    std::tie(p, sz) = std::get_temporary_buffer<std::string>(4);
    std::uninitialized_fill_n(p, sz, "Example");
    for (std::string* i = p; i != p+sz; ++i) {
        std::cout << *i << '\n';
        i->~basic_string<char>();
    }
    std::return_temporary_buffer(p);
}

