/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_exp2.exe ./cpp/numeric_math_exp2.cpp && (cd ../_build/cpp/;./numeric_math_exp2.exe)
https://en.cppreference.com/w/cpp/numeric/math/exp2
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "exp2(4) = " << std::exp2(4) << '\n'
              << "exp2(0.5) = " << std::exp2(0.5) << '\n'
              << "exp2(-4) = " << std::exp2(-4) << '\n';
    // special values
    std::cout << "exp2(-0) = " << std::exp2(-0.0) << '\n'
              << "exp2(-Inf) = " << std::exp2(-INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "exp2(1024) = " << std::exp2(1024) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

