/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_fmax.exe ./cpp/numeric_math_fmax.cpp && (cd ../_build/cpp/;./numeric_math_fmax.exe)
https://en.cppreference.com/w/cpp/numeric/math/fmax
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "fmax(2,1)    = " << std::fmax(2,1) << '\n'
              << "fmax(-Inf,0) = " << std::fmax(-INFINITY,0) << '\n'
              << "fmax(NaN,-1) = " << std::fmax(NAN,-1) << '\n';
}

