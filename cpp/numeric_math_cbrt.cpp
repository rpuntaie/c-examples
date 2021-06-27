/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_cbrt.exe ./cpp/numeric_math_cbrt.cpp && (cd ../_build/cpp/;./numeric_math_cbrt.exe)
https://en.cppreference.com/w/cpp/numeric/math/cbrt
*/
#include <iostream>
#include <cmath>
#include <limits>
int main()
{
    // normal use
    std::cout << "cbrt(729) = " << std::cbrt(729) << '\n'
              << "cbrt(-0.125) = " << std::cbrt(-0.125) << '\n';
    // special values
    std::cout << "cbrt(-0) = " << std::cbrt(-0.0) << '\n'
              << "cbrt(+inf) = " << std::cbrt(INFINITY) << '\n';
    // accuracy
    std::cout.precision(std::numeric_limits<double>::max_digits10);
    std::cout << "cbrt(343)      = " << std::cbrt(343) << '\n';
    std::cout << "pow(343,1.0/3) = " << std::pow(343, 1.0/3) << '\n';
}

