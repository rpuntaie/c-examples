/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_asinh.exe ./cpp/numeric_complex_asinh.cpp && (cd ../_build/cpp/;./numeric_complex_asinh.exe)
https://en.cppreference.com/w/cpp/numeric/complex/asinh
*/
#include <iostream>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z1(0, -2);
    std::cout << "asinh" << z1 << " = " << std::asinh(z1) << '\n';
    std::complex<double> z2(-0.0, -2);
    std::cout << "asinh" << z2 << " (the other side of the cut) = "
              << std::asinh(z2) << '\n';
    // for any z, asinh(z) = asin(iz)/i
    std::complex<double> z3(1,2);
    std::complex<double> i(0,1);
    std::cout << "asinh" << z3 << " = " << std::asinh(z3) << '\n'
              << "asin" << z3*i << "/i = " << std::asin(z3*i)/i << '\n';
}

