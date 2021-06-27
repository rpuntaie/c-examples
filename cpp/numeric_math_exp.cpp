/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_exp.exe ./cpp/numeric_math_exp.cpp && (cd ../_build/cpp/;./numeric_math_exp.exe)
https://en.cppreference.com/w/cpp/numeric/math/exp
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "exp(1) = e¹ = " << std::setprecision(16) << std::exp(1) << '\n'
              << "FV of $100, continuously compounded at 3% for 1 year = "
              << std::setprecision(6) << 100*std::exp(0.03) << '\n';
    // special values
    std::cout << "exp(-0) = " << std::exp(-0.0) << '\n'
              << "exp(-Inf) = " << std::exp(-INFINITY) << '\n';
    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "exp(710) = " << std::exp(710) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

