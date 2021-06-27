/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_scalbn.exe ./cpp/numeric_math_scalbn.cpp && (cd ../_build/cpp/;./numeric_math_scalbn.exe)
https://en.cppreference.com/w/cpp/numeric/math/scalbn
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "scalbn(7, -4) = " << std::scalbn(7, -4) << '\n'
              << "scalbn(1, -1074) = " << std::scalbn(1, -1074)
              << " (minimum positive subnormal double)\n"
              << "scalbn(nextafter(1,0), 1024) = "
              << std::scalbn(std::nextafter(1,0), 1024)
              << " (largest finite double)\n";
    // special values
    std::cout << "scalbn(-0, 10) = " << std::scalbn(-0.0, 10) << '\n'
              << "scalbn(-Inf, -1) = " << std::scalbn(-INFINITY, -1) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "scalbn(1, 1024) = " << std::scalbn(1, 1024) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

