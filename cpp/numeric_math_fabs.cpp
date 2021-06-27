/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_fabs.exe ./cpp/numeric_math_fabs.cpp && (cd ../_build/cpp/;./numeric_math_fabs.exe)
https://en.cppreference.com/w/cpp/numeric/math/fabs
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "abs(+3.0) = " << std::abs(+3.0) << '\n'
              << "abs(-3.0) = " << std::abs(-3.0) << '\n';
    // special values
    std::cout << "abs(-0.0) = " << std::abs(-0.0) << '\n'
              << "abs(-Inf) = " << std::abs(-INFINITY) << '\n'
              << "abs(-NaN) = " << std::abs(-NAN) << '\n';
}

