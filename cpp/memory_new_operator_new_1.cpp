/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_operator_new_1.exe ./cpp/memory_new_operator_new_1.cpp && (cd ../_build/cpp/;./memory_new_operator_new_1.exe)
https://en.cppreference.com/w/cpp/memory/new/operator_new
*/
#include <iostream>
// class-specific allocation functions
struct X {
    static void* operator new(std::size_t sz)
    {
        std::cout << "custom new for size " << sz << '\n';
        return ::operator new(sz);
    }
    static void* operator new[](std::size_t sz)
    {
        std::cout << "custom new[] for size " << sz << '\n';
        return ::operator new(sz);
    }
};
int main() {
     X* p1 = new X;
     delete p1;
     X* p2 = new X[10];
     delete[] p2;
}

