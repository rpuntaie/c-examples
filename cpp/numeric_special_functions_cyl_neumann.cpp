/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_cyl_neumann.exe ./cpp/numeric_special_functions_cyl_neumann.cpp && (cd ../_build/cpp/;./numeric_special_functions_cyl_neumann.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann
*/
#include <cmath>
#include <iostream>
int main()
{
    double pi = std::acos(-1);
    double x = 1.2345;
    // spot check for ν == 0.5
    std::cout << "N_.5(" << x << ") = " << std::cyl_neumann(.5, x) << '\n'
              << "calculated via J = " << 
              (std::cyl_bessel_j(.5,x)*std::cos(.5*pi)
             - std::cyl_bessel_j(-.5,x))/std::sin(.5*pi) << '\n';
}

