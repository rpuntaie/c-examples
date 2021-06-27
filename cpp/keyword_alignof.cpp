/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_alignof.exe ./cpp/keyword_alignof.cpp && (cd ../_build/cpp/;./keyword_alignof.exe)
https://en.cppreference.com/w/cpp/keyword/alignof
*/
#include <iostream>
#include <cstddef>
int main()
{
    std::cout << alignof(std::max_align_t) << '\n';
}

