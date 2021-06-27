/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_uninitialized_copy_n_1.exe ./cpp/memory_uninitialized_copy_n_1.cpp && (cd ../_build/cpp/;./memory_uninitialized_copy_n_1.exe)
https://en.cppreference.com/w/cpp/memory/uninitialized_copy_n
*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
int main()
{
    std::vector<std::string> v = {"This", "is", "an", "example"};
    std::string* p;
    std::size_t sz;
    std::tie(p, sz) = std::get_temporary_buffer<std::string>(v.size());
    sz = std::min(sz, v.size());
    std::uninitialized_copy_n(v.begin(), sz, p);
    for (std::string* i = p; i != p+sz; ++i) {
        std::cout << *i << ' ';
        i->~basic_string<char>();
    }
    std::return_temporary_buffer(p);
}

