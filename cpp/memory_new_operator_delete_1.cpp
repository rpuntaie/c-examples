/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_operator_delete_1.exe ./cpp/memory_new_operator_delete_1.cpp && (cd ../_build/cpp/;./memory_new_operator_delete_1.exe)
https://en.cppreference.com/w/cpp/memory/new/operator_delete
*/
#include <iostream>
// sized class-specific deallocation functions
struct X {
    static void operator delete(void* ptr, std::size_t sz)
    {
        std::cout << "custom delete for size " << sz << '\n';
        ::operator delete(ptr);
    }
    static void operator delete[](void* ptr, std::size_t sz)
    {
        std::cout << "custom delete for size " << sz << '\n';
        ::operator delete(ptr);
    }
};
int main() {
     X* p1 = new X;
     delete p1;
     X* p2 = new X[10];
     delete[] p2;
}

