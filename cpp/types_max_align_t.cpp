/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_max_align_t.exe ./cpp/types_max_align_t.cpp && (cd ../_build/cpp/;./types_max_align_t.exe)
https://en.cppreference.com/w/cpp/types/max_align_t
*/
#include <iostream>
#include <cstddef>
int main()
{
    std::cout << alignof(std::max_align_t) << '\n';
}

