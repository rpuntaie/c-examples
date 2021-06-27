/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_trunc.exe ./cpp/numeric_math_trunc.cpp && (cd ../_build/cpp/;./numeric_math_trunc.exe)
https://en.cppreference.com/w/cpp/numeric/math/trunc
*/
#include <cmath>
#include <iostream>
int main()
{
    std::cout << std::fixed
              << "trunc(+2.7) = " << std::trunc(+2.7) << '\n'
              << "trunc(-2.9) = " << std::trunc(-2.9) << '\n'
              << "trunc(-0.0) = " << std::trunc(-0.0) << '\n'
              << "trunc(-Inf) = " << std::trunc(-INFINITY) << '\n';
}

