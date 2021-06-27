/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_assoc_laguerre.exe ./cpp/numeric_special_functions_assoc_laguerre.cpp && (cd ../_build/cpp/;./numeric_special_functions_assoc_laguerre.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre
*/
#include <cmath>
#include <iostream>
double L1(unsigned m, double x) { return -x + m + 1; }
double L2(unsigned m, double x) { return 0.5*(x*x-2*(m+2)*x+(m+1)*(m+2)); }
int main()
{
    // spot-checks
    std::cout << std::assoc_laguerre(1, 10, 0.5) << '=' << L1(10, 0.5) << '\n'
              << std::assoc_laguerre(2, 10, 0.5) << '=' << L2(10, 0.5) << '\n';
}

