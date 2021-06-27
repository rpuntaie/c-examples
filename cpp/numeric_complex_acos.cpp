/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_acos.exe ./cpp/numeric_complex_acos.cpp && (cd ../_build/cpp/;./numeric_complex_acos.exe)
https://en.cppreference.com/w/cpp/numeric/complex/acos
*/
#include <iostream>
#include <cmath>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z1(-2, 0);
    std::cout << "acos" << z1 << " = " << std::acos(z1) << '\n';
    std::complex<double> z2(-2, -0.0);
    std::cout << "acos" << z2 << " (the other side of the cut) = "
              << std::acos(z2) << '\n';
    // for any z, acos(z) = pi - acos(-z)
    const double pi = std::acos(-1);
    std::complex<double> z3 = pi - std::acos(z2);
    std::cout << "cos(pi - acos" << z2 << ") = " << std::cos(z3) << '\n';
}

