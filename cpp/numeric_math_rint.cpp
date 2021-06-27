/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_rint.exe ./cpp/numeric_math_rint.cpp && (cd ../_build/cpp/;./numeric_math_rint.exe)
https://en.cppreference.com/w/cpp/numeric/math/rint
*/
#include <iostream>
#include <cmath>
#include <cfenv>
#include <climits>
int main()
{
#pragma STDC FENV_ACCESS ON
    std::fesetround(FE_TONEAREST);
    std::cout << "rounding to nearest (halfway cases to even):\n"
              << "rint(+2.3) = " << std::rint(2.3)
              << "  rint(+2.5) = " << std::rint(2.5)
              << "  rint(+3.5) = " << std::rint(3.5) << '\n'
              << "rint(-2.3) = " << std::rint(-2.3)
              << "  rint(-2.5) = " << std::rint(-2.5)
              << "  rint(-3.5) = " << std::rint(-3.5) << '\n';
    std::fesetround(FE_DOWNWARD);
    std::cout << "rounding down:\n" 
              << "rint(+2.3) = " << std::rint(2.3)
              << "  rint(+2.5) = " << std::rint(2.5)
              << "  rint(+3.5) = " << std::rint(3.5) << '\n'
              << "rint(-2.3) = " << std::rint(-2.3)
              << "  rint(-2.5) = " << std::rint(-2.5)
              << "  rint(-3.5) = " << std::rint(-3.5) << '\n'
              << "rounding down with lrint\n" 
              << "lrint(+2.3) = " << std::lrint(2.3)
              << "  lrint(+2.5) = " << std::lrint(2.5)
              << "  lrint(+3.5) = " << std::lrint(3.5) << '\n'
              << "lrint(-2.3) = " << std::lrint(-2.3)
              << "  lrint(-2.5) = " << std::lrint(-2.5)
              << "  lrint(-3.5) = " << std::lrint(-3.5) << '\n';
    std::cout << "lrint(-0.0) = " << std::lrint(-0.0)  << '\n'
              << "lrint(-Inf) = " << std::lrint(-INFINITY) << '\n';
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "std::rint(0.1) = " << std::rint(.1) << '\n';
    if (std::fetestexcept(FE_INEXACT))
              std::cout << "    FE_INEXACT was raised\n";
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "std::lrint(LONG_MIN-2048.0) = "
              << std::lrint(LONG_MIN-2048.0) << '\n';
    if (std::fetestexcept(FE_INVALID))
              std::cout << "    FE_INVALID was raised\n";
}

