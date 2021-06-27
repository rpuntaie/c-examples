/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_log2.exe ./cpp/numeric_math_log2.cpp && (cd ../_build/cpp/;./numeric_math_log2.exe)
https://en.cppreference.com/w/cpp/numeric/math/log2
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log2(65536) = " << std::log2(65536) << '\n'
              << "log2(0.125) = " << std::log2(0.125) << '\n'
              << "log2(0x020f) = " << std::log2(0x020f)
              << " (highest set bit is in position 9)\n"
              << "base-5 logarithm of 125 = " << std::log2(125)/std::log2(5) << '\n';
    // special values
    std::cout << "log2(1) = " << std::log2(1) << '\n'
              << "log2(+Inf) = " << std::log2(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log2(0) = " << std::log2(0) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}

