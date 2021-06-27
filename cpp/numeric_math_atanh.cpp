/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_atanh.exe ./cpp/numeric_math_atanh.cpp && (cd ../_build/cpp/;./numeric_math_atanh.exe)
https://en.cppreference.com/w/cpp/numeric/math/atanh
*/
#include <iostream>
#include <cmath>
#include <cfloat>
#include <cerrno>
#include <cfenv>
#include <cstring>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "atanh(0) = " << std::atanh(0) << '\n'
              << "atanh(-0) = " << std::atanh(-0.0) << '\n'
              << "atanh(0.9) = " << std::atanh(0.9) << '\n';
    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "atanh(-1) = " << std::atanh(-1) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}

