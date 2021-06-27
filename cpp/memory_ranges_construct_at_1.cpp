/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_construct_at_1.exe ./cpp/memory_ranges_construct_at_1.cpp && (cd ../_build/cpp/;./memory_ranges_construct_at_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/construct_at
*/
#include <iostream>
#include <memory>
struct S {
    int x;
    float y;
    double z;
    S(int x, float y, double z) : x{x}, y{y}, z{z} { std::cout << "S::S();\n"; }
    ~S() { std::cout << "S::~S();\n"; }
    void print() const {
        std::cout << "S { x=" << x << "; y=" << y << "; z=" << z << "; };\n";
    }
};
int main()
{
    alignas(S) unsigned char buf[sizeof(S)];
    S* ptr = std::ranges::construct_at(reinterpret_cast<S*>(buf), 42, 2.71828f, 3.1415);
    ptr->print();
    std::ranges::destroy_at(ptr);
}

