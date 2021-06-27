/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_signbit.exe ./cpp/numeric_math_signbit.cpp && (cd ../_build/cpp/;./numeric_math_signbit.exe)
https://en.cppreference.com/w/cpp/numeric/math/signbit
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << std::boolalpha
              << "signbit(+0.0) = " << std::signbit(+0.0) << '\n'
              << "signbit(-0.0) = " << std::signbit(-0.0) << '\n';
}

