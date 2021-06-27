/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_legendre.exe ./cpp/numeric_special_functions_legendre.cpp && (cd ../_build/cpp/;./numeric_special_functions_legendre.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/legendre
*/
#include <cmath>
#include <iostream>
double P3(double x) { return 0.5*(5*std::pow(x,3) - 3*x); }
double P4(double x) { return 0.125*(35*std::pow(x,4)-30*x*x+3); }
int main()
{
    // spot-checks
    std::cout << std::legendre(3, 0.25) << '=' << P3(0.25) << '\n'
              << std::legendre(4, 0.25) << '=' << P4(0.25) << '\n';
}

