/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_ceil_1.exe ./cpp/numeric_math_ceil_1.cpp && (cd ../_build/cpp/;./numeric_math_ceil_1.exe)
https://en.cppreference.com/w/cpp/numeric/math/ceil
*/
#include <cmath>
#include <iostream>
int main()
{
    std::cout << std::fixed
              << "ceil(+2.4) = " << std::ceil(+2.4) << '\n'
              << "ceil(-2.4) = " << std::ceil(-2.4) << '\n'
              << "ceil(-0.0) = " << std::ceil(-0.0) << '\n'
              << "ceil(-Inf) = " << std::ceil(-INFINITY) << '\n';
}

