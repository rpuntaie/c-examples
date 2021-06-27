/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_copysign.exe ./cpp/numeric_math_copysign.cpp && (cd ../_build/cpp/;./numeric_math_copysign.exe)
https://en.cppreference.com/w/cpp/numeric/math/copysign
*/
#include <iostream>
#include <cmath>
int main(void)
{
    std::cout << std::showpos
              << "copysign(1.0,+2.0) = " << std::copysign(1.0,+2.0) << '\n'
              << "copysign(1.0,-2.0) = " << std::copysign(1.0,-2.0) << '\n'
              << "copysign(inf,-2.0) = " << std::copysign(INFINITY,-2.0) << '\n'
              << "copysign(NaN,-2.0) = " << std::copysign(NAN,-2.0) << '\n';
}

