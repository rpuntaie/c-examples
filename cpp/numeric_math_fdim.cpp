/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_fdim.exe ./cpp/numeric_math_fdim.cpp && (cd ../_build/cpp/;./numeric_math_fdim.exe)
https://en.cppreference.com/w/cpp/numeric/math/fdim
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "fdim(4, 1) = " << std::fdim(4, 1)
              << " fdim(1, 4) = " << std::fdim(1, 4) << '\n'
              << "fdim(4,-1) = " << std::fdim(4, -1)
              << " fdim(1,-4) = " << std::fdim(1, -4) << '\n';
    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fdim(1e308, -1e308) = " << std::fdim(1e308, -1e308) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

