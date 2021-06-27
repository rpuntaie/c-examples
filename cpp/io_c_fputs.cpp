/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_fputs.exe ./cpp/io_c_fputs.cpp && (cd ../_build/cpp/;./io_c_fputs.exe)
https://en.cppreference.com/w/cpp/io/c/fputs
*/
#include <cstdio>
int main(void)
{
    int rc = std::fputs("Hello World", stdout);
    if (rc == EOF)
       std::perror("fputs()"); // POSIX requires that errno is set
}

