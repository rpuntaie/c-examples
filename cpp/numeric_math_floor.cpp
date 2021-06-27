/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_floor.exe ./cpp/numeric_math_floor.cpp && (cd ../_build/cpp/;./numeric_math_floor.exe)
https://en.cppreference.com/w/cpp/numeric/math/floor
*/
#include <cmath>
#include <iostream>
int main()
{
    std::cout << std::fixed
              << "floor(+2.7) = " << std::floor(+2.7) << '\n'
              << "floor(-2.7) = " << std::floor(-2.7) << '\n'
              << "floor(-0.0) = " << std::floor(-0.0) << '\n'
              << "floor(-Inf) = " << std::floor(-INFINITY) << '\n';
}

