/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_remainder.exe ./cpp/numeric_math_remainder.cpp && (cd ../_build/cpp/;./numeric_math_remainder.exe)
https://en.cppreference.com/w/cpp/numeric/math/remainder
*/
#include <iostream>
#include <cmath>
#include <cfenv>
#pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "remainder(+5.1, +3.0) = " << std::remainder(5.1,3) << '\n'
              << "remainder(-5.1, +3.0) = " << std::remainder(-5.1,3) << '\n'
              << "remainder(+5.1, -3.0) = " << std::remainder(5.1,-3) << '\n'
              << "remainder(-5.1, -3.0) = " << std::remainder(-5.1,-3) << '\n';
    // special values
    std::cout << "remainder(-0.0, 1.0) = " << std::remainder(-0.0, 1) << '\n'
              << "remainder(5.1, Inf) = " << std::remainder(5.1, INFINITY) << '\n';
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "remainder(+5.1, 0) = " << std::remainder(5.1, 0) << '\n';
    if(fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}

