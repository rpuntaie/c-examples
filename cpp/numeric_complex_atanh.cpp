/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_atanh.exe ./cpp/numeric_complex_atanh.cpp && (cd ../_build/cpp/;./numeric_complex_atanh.exe)
https://en.cppreference.com/w/cpp/numeric/complex/atanh
*/
#include <iostream>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z1(2, 0);
    std::cout << "atanh" << z1 << " = " << std::atanh(z1) << '\n';
    std::complex<double> z2(2, -0.0);
    std::cout << "atanh" << z2 << " (the other side of the cut) = "
              << std::atanh(z2) << '\n';
    // for any z, atanh(z) = atanh(iz)/i
    std::complex<double> z3(1,2);
    std::complex<double> i(0,1);
    std::cout << "atanh" << z3 << " = " << std::atanh(z3) << '\n'
              << "atan" << z3*i << "/i = " << std::atan(z3*i)/i << '\n';
}

