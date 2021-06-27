/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_c_aligned_alloc.exe ./cpp/memory_c_aligned_alloc.cpp && (cd ../_build/cpp/;./memory_c_aligned_alloc.exe)
https://en.cppreference.com/w/cpp/memory/c/aligned_alloc
*/
#include <cstdio>
#include <cstdlib>
int main()
{
    int* p1 = static_cast<int*>(std::malloc(10*sizeof *p1));
    std::printf("default-aligned address:   %p\n", static_cast<void*>(p1));
    std::free(p1);
    int* p2 = static_cast<int*>(std::aligned_alloc(1024, 1024));
    std::printf("1024-byte aligned address: %p\n", static_cast<void*>(p2));
    std::free(p2);
}

