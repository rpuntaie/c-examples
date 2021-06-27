/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_fmin.exe ./cpp/numeric_math_fmin.cpp && (cd ../_build/cpp/;./numeric_math_fmin.exe)
https://en.cppreference.com/w/cpp/numeric/math/fmin
*/
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "fmin(2,1)    = " << std::fmin(2,1) << '\n'
              << "fmin(-Inf,0) = " << std::fmin(-INFINITY,0) << '\n'
              << "fmin(NaN,-1) = " << std::fmin(NAN,-1) << '\n';
}

