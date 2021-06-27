/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_alignas_1.exe ./cpp/language_alignas_1.cpp && (cd ../_build/cpp/;./language_alignas_1.exe)
https://en.cppreference.com/w/cpp/language/alignas
*/
// every object of type struct_float will be aligned to alignof(float) boundary
// (usually 4)
struct alignas(float) struct_float {
    // your definition here
};
// every object of type sse_t will be aligned to 256-byte boundary
struct alignas(256) sse_t
{
    float sse_data[4];
};
// the array "cacheline" will be aligned to 128-byte boundary
alignas(128) char cacheline[128];
#include <iostream>
int main()
{
    sse_t x, y, z;
    struct default_aligned { float data[4]; } a, b, c;
    std::cout << "alignof(struct_float) = " << alignof(struct_float) << '\n'
              << "alignof(sse_t) = " << alignof(sse_t) << '\n'
              << "alignof(alignas(128) char[128]) = " 
                  << alignof(alignas(128) char[128]) << "\n\n";
    std::cout << std::hex << std::showbase
              << "&x: " << &x << '\n'
              << "&y: " << &y << '\n'
              << "&z: " << &z << '\n'
              << "&a: " << &a << '\n'
              << "&b: " << &b << '\n'
              << "&c: " << &c << '\n';
}

