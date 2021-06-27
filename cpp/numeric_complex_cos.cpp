/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_cos.exe ./cpp/numeric_complex_cos.cpp && (cd ../_build/cpp/;./numeric_complex_cos.exe)
https://en.cppreference.com/w/cpp/numeric/complex/cos
*/
#include <iostream>
#include <cmath>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z(1, 0); // behaves like real cosine along the real line
    std::cout << "cos" << z << " = " << std::cos(z)
              << " ( cos(1) = " << std::cos(1) << ")\n";
    std::complex<double> z2(0, 1); // behaves like real cosh along the imaginary line
    std::cout << "cos" << z2 << " = " << std::cos(z2)
              << " (cosh(1) = " << std::cosh(1) << ")\n";
}

