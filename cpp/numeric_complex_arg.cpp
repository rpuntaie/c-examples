/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_arg.exe ./cpp/numeric_complex_arg.cpp && (cd ../_build/cpp/;./numeric_complex_arg.exe)
https://en.cppreference.com/w/cpp/numeric/complex/arg
*/
#include <iostream>
#include <complex>
int main() 
{
    std::complex<double> z1(1, 0); 
    std::cout << "phase angle of " << z1 << " is " << std::arg(z1) << '\n';
    std::complex<double> z2(0, 1); 
    std::cout << "phase angle of " << z2 << " is " << std::arg(z2) << '\n';
    std::complex<double> z3(-1, 0); 
    std::cout << "phase angle of " << z3 << " is " << std::arg(z3) << '\n';
    std::complex<double> z4(-1, -0.0); 
    std::cout << "phase angle of " << z4 << " (the other side of the cut) is "
              << std::arg(z4) << '\n';
}

