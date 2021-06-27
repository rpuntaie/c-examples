/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_errno.exe ./cpp/error_errno.cpp && (cd ../_build/cpp/;./error_errno.exe)
https://en.cppreference.com/w/cpp/error/errno
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <clocale>
int main()
{
    double not_a_number = std::log(-1.0);
    if (errno == EDOM) {
        std::cout << "log(-1) failed: " << std::strerror(errno) << '\n';
        std::setlocale(LC_MESSAGES, "de_DE.utf8");
        std::cout << "Or, in German, " << std::strerror(errno) << '\n';
    }
}

