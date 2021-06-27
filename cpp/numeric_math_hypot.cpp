/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_hypot.exe ./cpp/numeric_math_hypot.cpp && (cd ../_build/cpp/;./numeric_math_hypot.exe)
https://en.cppreference.com/w/cpp/numeric/math/hypot
*/
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cstring>
#pragma STDC FENV_ACCESS ON
int main()
{
    // typical usage
    std::cout << "(1,1) cartesian is (" << std::hypot(1,1)
              << ',' << std::atan2(1,1) << ") polar\n";
    // special values
    std::cout << "hypot(NAN,INFINITY) = " << std::hypot(NAN,INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "hypot(DBL_MAX,DBL_MAX) = " << std::hypot(DBL_MAX,DBL_MAX) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno = ERANGE " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}

