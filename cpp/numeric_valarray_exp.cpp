/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_exp.exe ./cpp/numeric_valarray_exp.cpp && (cd ../_build/cpp/;./numeric_valarray_exp.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/exp
*/
#include <iostream>
#include <complex>
#include <valarray>
int main()
{
    const double pi = std::acos(-1);
    std::valarray<std::complex<double>> v = {
        {0, 0}, {0, pi/2}, {0, pi}, {0, 3*pi/2}, {0, 2*pi}
    };
    std::valarray<std::complex<double>> v2 = std::exp(v);
    for(auto n : v2) {
        std::cout << std::showpos << std::fixed << n << '\n';
    }
}

