/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_tanh.exe ./cpp/numeric_complex_tanh.cpp && (cd ../_build/cpp/;./numeric_complex_tanh.exe)
https://en.cppreference.com/w/cpp/numeric/complex/tanh
*/
#include <iostream>
#include <cmath>
#include <complex>
int main()
{
    std::cout << std::fixed;
    std::complex<double> z(1, 0); // behaves like real tanh along the real line
    std::cout << "tanh" << z << " = " << std::tanh(z)
              << " (tanh(1) = " << std::tanh(1) << ")\n";
    std::complex<double> z2(0, 1); // behaves like tangent along the imaginary line
    std::cout << "tanh" << z2 << " = " << std::tanh(z2)
              << " ( tan(1) = " << std::tan(1) << ")\n";
}

