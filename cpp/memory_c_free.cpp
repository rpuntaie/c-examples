/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_c_free.exe ./cpp/memory_c_free.cpp && (cd ../_build/cpp/;./memory_c_free.exe)
https://en.cppreference.com/w/cpp/memory/c/free
*/
#include <cstdlib>
int main()
{
    int* p1 = (int*)std::malloc(10*sizeof *p1);
    std::free(p1); // every allocated pointer must be freed
    int* p2 = (int*)std::calloc(10, sizeof *p2);
    int* p3 = (int*)std::realloc(p2, 1000*sizeof *p3);
    if(p3) // p3 not null means p2 was freed by std::realloc
       std::free(p3);
    else // p3 null means p2 was not freed
       std::free(p2);
}

