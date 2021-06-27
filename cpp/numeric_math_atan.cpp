/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_atan.exe ./cpp/numeric_math_atan.cpp && (cd ../_build/cpp/;./numeric_math_atan.exe)
https://en.cppreference.com/w/cpp/numeric/math/atan
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "atan(1) = " << atan(1) << " 4*atan(1) = " << 4*atan(1) << '\n';
    // special values
    std::cout << "atan(Inf) = " << atan(INFINITY)
              << " 2*atan(Inf) = " << 2*atan(INFINITY) << '\n'
              << "atan(-0.0) = " << atan(-0.0) << '\n'
              << "atan(+0.0) = " << atan(0) << '\n';
}

