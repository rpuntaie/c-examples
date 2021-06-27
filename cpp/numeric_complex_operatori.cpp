/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_operatori.exe ./cpp/numeric_complex_operatori.cpp && (cd ../_build/cpp/;./numeric_complex_operatori.exe)
https://en.cppreference.com/w/cpp/numeric/complex/operator""i
*/
#include <iostream>
#include <complex>
int main()
{
    using namespace std::complex_literals;
    std::complex<double> c = 1.0 + 1i;
    std::cout << "abs" << c << " = " << std::abs(c) << '\n';
    std::complex<float> z = 3.0f + 4.0if;
    std::cout << "abs" << z << " = " << std::abs(z) << '\n';
}

