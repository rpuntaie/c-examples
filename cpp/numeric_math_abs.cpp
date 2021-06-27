/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_abs.exe ./cpp/numeric_math_abs.cpp && (cd ../_build/cpp/;./numeric_math_abs.exe)
https://en.cppreference.com/w/cpp/numeric/math/abs
*/
#include <iostream>
#include <cstdlib>
#include <climits>
int main()
{
    std::cout << "abs(+3) = " << std::abs(3) << '\n'
              << "abs(-3) = " << std::abs(-3) << '\n';
//  std::cout << std::abs(INT_MIN); // undefined behavior on 2's complement systems
}

