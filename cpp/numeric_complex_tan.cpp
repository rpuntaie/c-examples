/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_tan.exe ./cpp/numeric_complex_tan.cpp && (cd ../_build/cpp/;./numeric_complex_tan.exe)
https://en.cppreference.com/w/cpp/numeric/complex/tan
*/
#include <iostream>
#include <cmath>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z(1, 0); // behaves like real tangent along the real line
    std::cout << "tan" << z << " = " << std::tan(z)
              << " ( tan(1) = " << std::tan(1) << ")\n";
    std::complex<double> z2(0, 1); // behaves like tanh along the imaginary line
    std::cout << "tan" << z2 << " = " << std::tan(z2)
              << " (tanh(1) = " << std::tanh(1) << ")\n";
}

