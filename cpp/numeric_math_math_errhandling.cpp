/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_math_errhandling.exe ./cpp/numeric_math_math_errhandling.cpp && (cd ../_build/cpp/;./numeric_math_math_errhandling.exe)
https://en.cppreference.com/w/cpp/numeric/math/math_errhandling
*/
#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "MATH_ERRNO is "
              << (math_errhandling & MATH_ERRNO ? "set" : "not set") << '\n'
              << "MATH_ERREXCEPT is "
              << (math_errhandling & MATH_ERREXCEPT ? "set" : "not set") << '\n';
    std::feclearexcept(FE_ALL_EXCEPT);
    errno = 0;
    std::cout <<  "log(0) = " << std::log(0) << '\n';
    if(errno == ERANGE)
            std::cout << "errno = ERANGE (" << std::strerror(errno) << ")\n";
    if(std::fetestexcept(FE_DIVBYZERO))
        std::cout << "FE_DIVBYZERO (pole error) reported\n";
}

