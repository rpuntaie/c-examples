/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_sinh.exe ./cpp/numeric_math_sinh.cpp && (cd ../_build/cpp/;./numeric_math_sinh.exe)
https://en.cppreference.com/w/cpp/numeric/math/sinh
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "sinh(1) = " << std::sinh(1) << '\n'
              << "sinh(-1) = " << std::sinh(-1) << '\n'
              << "log(sinh(1)+cosh(1)) = "
              << std::log(std::sinh(1)+std::cosh(1)) << '\n';
    // special values
    std::cout << "sinh(+0) = " << std::sinh(0.0) << '\n'
              << "sinh(-0) = " << std::sinh(-0.0) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "sinh(710.5) = " << std::sinh(710.5) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

