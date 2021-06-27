/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_ldexp.exe ./cpp/numeric_math_ldexp.cpp && (cd ../_build/cpp/;./numeric_math_ldexp.exe)
https://en.cppreference.com/w/cpp/numeric/math/ldexp
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "ldexp(7, -4) = " << std::ldexp(7, -4) << '\n'
              << "ldexp(1, -1074) = " << std::ldexp(1, -1074)
              << " (minimum positive subnormal double)\n"
              << "ldexp(nextafter(1,0), 1024) = "
              << std::ldexp(std::nextafter(1,0), 1024)
              << " (largest finite double)\n";
    // special values
    std::cout << "ldexp(-0, 10) = " << std::ldexp(-0.0, 10) << '\n'
              << "ldexp(-Inf, -1) = " << std::ldexp(-INFINITY, -1) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "ldexp(1, 1024) = " << std::ldexp(1, 1024) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

