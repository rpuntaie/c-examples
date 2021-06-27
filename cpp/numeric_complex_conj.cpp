/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_conj.exe ./cpp/numeric_complex_conj.cpp && (cd ../_build/cpp/;./numeric_complex_conj.exe)
https://en.cppreference.com/w/cpp/numeric/complex/conj
*/
#include <iostream>
#include <complex>
int main()
{
    std::complex<double> z(1,2);
    std::cout << "The conjugate of " << z << " is " << std::conj(z) << '\n'
              << "Their product is " << z*std::conj(z) << '\n';
}

