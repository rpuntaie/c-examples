/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_asinh.exe ./cpp/numeric_math_asinh.cpp && (cd ../_build/cpp/;./numeric_math_asinh.exe)
https://en.cppreference.com/w/cpp/numeric/math/asinh
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "asinh(1) = " << std::asinh(1) << '\n'
              << "asinh(-1) = " << std::asinh(-1) << '\n';
    // special values
    std::cout << "asinh(+0) = " << std::asinh(+0.0) << '\n'
              << "asinh(-0) = " <<  std::asinh(-0.0) << '\n';
}

