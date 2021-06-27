/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_acos.exe ./cpp/numeric_math_acos.cpp && (cd ../_build/cpp/;./numeric_math_acos.exe)
https://en.cppreference.com/w/cpp/numeric/math/acos
*/
#include <cmath>
#include <iostream>
#include <cerrno>
#include <cfenv>
#include <cstring>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "acos(-1) = " << acos(-1) << '\n'
              << "acos(0.0) = " << acos(0.0) << " 2*acos(0.0) = " << 2*acos(0) << '\n'
              << "acos(0.5) = " << acos(0.5) << " 3*acos(0.5) = " << 3*acos(0.5) << '\n'
              << "acos(1) = " << acos(1) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "acos(1.1) = " << acos(1.1) << '\n';
    if (errno == EDOM)
        std::cout << "    errno == EDOM: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised" << '\n';
}

