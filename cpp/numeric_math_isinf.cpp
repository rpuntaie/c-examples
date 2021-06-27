/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_isinf.exe ./cpp/numeric_math_isinf.cpp && (cd ../_build/cpp/;./numeric_math_isinf.exe)
https://en.cppreference.com/w/cpp/numeric/math/isinf
*/
#include <iostream>
#include <cmath>
#include <cfloat>
int main()
{
    std::cout << std::boolalpha
              << "isinf(NaN) = " << std::isinf(NAN) << '\n'
              << "isinf(Inf) = " << std::isinf(INFINITY) << '\n'
              << "isinf(0.0) = " << std::isinf(0.0) << '\n'
              << "isinf(exp(800)) = " << std::isinf(std::exp(800)) << '\n'
              << "isinf(DBL_MIN/2.0) = " << std::isinf(DBL_MIN/2.0) << '\n';
}

