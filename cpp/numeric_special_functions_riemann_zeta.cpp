/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_riemann_zeta.exe ./cpp/numeric_special_functions_riemann_zeta.cpp && (cd ../_build/cpp/;./numeric_special_functions_riemann_zeta.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta
*/
#include <cmath>
#include <iostream>
int main()
{
    // spot checks for well-known values
    std::cout << "ζ(-1) = " << std::riemann_zeta(-1) << '\n'
              << "ζ(0) = " << std::riemann_zeta(0) << '\n'
              << "ζ(1) = " << std::riemann_zeta(1) << '\n'
              << "ζ(0.5) = " << std::riemann_zeta(0.5) << '\n'
              << "ζ(2) = " << std::riemann_zeta(2) << ' '
              << "(π²/6 = " << std::pow(std::acos(-1),2)/6 << ")\n";
}

