/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_cosh.exe ./cpp/numeric_math_cosh.cpp && (cd ../_build/cpp/;./numeric_math_cosh.exe)
https://en.cppreference.com/w/cpp/numeric/math/cosh
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "cosh(1) = " << std::cosh(1) << '\n'
              << "cosh(-1) = " << std::cosh(-1) << '\n'
              << "log(sinh(1)+cosh(1)=" << std::log(std::sinh(1)+std::cosh(1)) << '\n';
    // special values
    std::cout << "cosh(+0) = " << std::cosh(0.0) << '\n'
              << "cosh(-0) = " << std::cosh(-0.0) << '\n';
    // error handling
    errno=0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "cosh(710.5) = " << std::cosh(710.5) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

