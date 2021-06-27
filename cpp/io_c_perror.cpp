/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_perror.exe ./cpp/io_c_perror.cpp && (cd ../_build/cpp/;./io_c_perror.exe)
https://en.cppreference.com/w/cpp/io/c/perror
*/
#include <cmath>
#include <cerrno>
#include <cstdio>
int main()
{
    double not_a_number = std::log(-1.0);
    if (errno == EDOM) {
        std::perror("log(-1) failed");
    }
    std::printf("%f\n", not_a_number);
}

