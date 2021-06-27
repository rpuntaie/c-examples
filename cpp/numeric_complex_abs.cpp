/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_abs.exe ./cpp/numeric_complex_abs.cpp && (cd ../_build/cpp/;./numeric_complex_abs.exe)
https://en.cppreference.com/w/cpp/numeric/complex/abs
*/
#include <iostream>
#include <complex>
int main()
{
    std::complex<double> z(1, 1);
    std::cout << z << " cartesian is rho = " << std::abs(z)
              << " theta = " << std::arg(z) << " polar\n";
}

