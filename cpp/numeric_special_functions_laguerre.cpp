/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_laguerre.exe ./cpp/numeric_special_functions_laguerre.cpp && (cd ../_build/cpp/;./numeric_special_functions_laguerre.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre
*/
#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#include <cmath>
#include <iostream>
double L1(double x) { return -x + 1; }
double L2(double x) { return 0.5*(x*x-4*x+2); }
int main()
{
    // spot-checks
    std::cout << std::laguerre(1, 0.5) << '=' << L1(0.5) << '\n'
              << std::laguerre(2, 0.5) << '=' << L2(0.5) << '\n';
}

