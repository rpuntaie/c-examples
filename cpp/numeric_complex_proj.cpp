/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_proj.exe ./cpp/numeric_complex_proj.cpp && (cd ../_build/cpp/;./numeric_complex_proj.exe)
https://en.cppreference.com/w/cpp/numeric/complex/proj
*/
#include <iostream>
#include <complex>
int main()
{
    std::complex<double> c1(1, 2);
    std::cout << "proj" << c1 << " = " << std::proj(c1) << '\n';
    std::complex<double> c2(INFINITY, -1);
    std::cout << "proj" << c2 << " = " << std::proj(c2) << '\n';
    std::complex<double> c3(0, -INFINITY);
    std::cout << "proj" << c3 << " = " << std::proj(c3) << '\n';
}

