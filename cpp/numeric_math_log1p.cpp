/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_log1p.exe ./cpp/numeric_math_log1p.cpp && (cd ../_build/cpp/;./numeric_math_log1p.exe)
https://en.cppreference.com/w/cpp/numeric/math/log1p
*/
#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log1p(0) = " << log1p(0) << '\n'
              << "Interest earned in 2 days on on $100, compounded daily at 1%\n"
              << " on a 30/360 calendar = "
              << 100*expm1(2*log1p(0.01/360)) << '\n'
              << "log(1+1e-16) = " << std::log(1+1e-16)
              << " log1p(1e-16) = " << std::log1p(1e-16) << '\n';
    // special values
    std::cout << "log1p(-0) = " << std::log1p(-0.0) << '\n'
              << "log1p(+Inf) = " << std::log1p(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log1p(-1) = " << std::log1p(-1) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}

