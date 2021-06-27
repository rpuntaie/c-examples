/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_sqrt.exe ./cpp/numeric_complex_sqrt.cpp && (cd ../_build/cpp/;./numeric_complex_sqrt.exe)
https://en.cppreference.com/w/cpp/numeric/complex/sqrt
*/
#include <iostream>
#include <complex>
int main()
{
    std::cout << "Square root of -4 is "
              << std::sqrt(std::complex<double>(-4, 0)) << '\n'
              << "Square root of (-4,-0), the other side of the cut, is "
              << std::sqrt(std::complex<double>(-4, -0.0)) << '\n';
}

