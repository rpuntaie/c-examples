/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_isnan.exe ./cpp/numeric_math_isnan.cpp && (cd ../_build/cpp/;./numeric_math_isnan.exe)
https://en.cppreference.com/w/cpp/numeric/math/isnan
*/
#include <iostream>
#include <cmath>
#include <cfloat>
int main()
{
    std::cout << std::boolalpha
              << "isnan(NaN) = " << std::isnan(NAN) << '\n'
              << "isnan(Inf) = " << std::isnan(INFINITY) << '\n'
              << "isnan(0.0) = " << std::isnan(0.0) << '\n'
              << "isnan(DBL_MIN/2.0) = " << std::isnan(DBL_MIN/2.0) << '\n'
              << "isnan(0.0 / 0.0)   = " << std::isnan(0.0/0.0) << '\n'
              << "isnan(Inf - Inf)   = " << std::isnan(INFINITY - INFINITY) << '\n';
}

