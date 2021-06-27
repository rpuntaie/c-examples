/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_puts.exe ./cpp/io_c_puts.cpp && (cd ../_build/cpp/;./io_c_puts.exe)
https://en.cppreference.com/w/cpp/io/c/puts
*/
#include <cstdio>
int main()
{
    int rc = std::puts("Hello World");
    if (rc == EOF)
       std::perror("puts()"); // POSIX requires that errno is set
}

