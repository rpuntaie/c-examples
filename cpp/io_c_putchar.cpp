/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_putchar.exe ./cpp/io_c_putchar.cpp && (cd ../_build/cpp/;./io_c_putchar.exe)
https://en.cppreference.com/w/cpp/io/c/putchar
*/
#include <cstdio>
int main()
{
    for (char c = 'a'; c != 'z'; c++)
        std::putchar(c);
    std::putchar('\n');
    // putchar return value is not equal to the argument
    int r = 0x1070;
    std::printf("\n0x%x\n", r);
    r = std::putchar(r);
    std::printf("\n0x%x\n", r);
}

