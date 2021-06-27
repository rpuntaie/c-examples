/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_atan.exe ./cpp/numeric_complex_atan.cpp && (cd ../_build/cpp/;./numeric_complex_atan.exe)
https://en.cppreference.com/w/cpp/numeric/complex/atan
*/
#include <iostream>
#include <complex>
#include <cmath>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z1(0, 2);
    std::cout << "atan" << z1 << " = " << std::atan(z1) << '\n';
    std::complex<double> z2(-0.0, 2);
    std::cout << "atan" << z2 << " (the other side of the cut) = "
              << std::atan(z2) << '\n';
    std::complex<double> z3(0, INFINITY);
    std::cout << "2*atan" << z3 << " = " << 2.0*std::atan(z3) << '\n';
}

