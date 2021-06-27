/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_sph_neumann.exe ./cpp/numeric_special_functions_sph_neumann.cpp && (cd ../_build/cpp/;./numeric_special_functions_sph_neumann.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann
*/
#include <cmath>
#include <iostream>
int main()
{
    // spot check for n == 1
    double x = 1.2345;
    std::cout << "n_1(" << x << ") = " << std::sph_neumann(1, x) << '\n';
    // exact solution for n_1
    std::cout << "-(cos x)/x^2 - (sin x)/x = "
              << -std::cos(x)/(x*x) - std::sin(x)/x << '\n';
}

