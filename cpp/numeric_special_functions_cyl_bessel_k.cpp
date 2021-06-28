/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_cyl_bessel_k.exe ./cpp/numeric_special_functions_cyl_bessel_k.cpp && (cd ../_build/cpp/;./numeric_special_functions_cyl_bessel_k.exe) || true
https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k
*/
#include <cmath>
#include <iostream>
int main()
{
    double pi = std::acos(-1);
    double x = 1.2345;
    // spot check for ν == 0.5
    std::cout << "K_.5(" << x << ") = " << std::cyl_bessel_k( .5, x) << '\n'
              << "calculated via I = " << 
              (pi/2)*(std::cyl_bessel_i(-.5,x)
                     -std::cyl_bessel_i(.5,x))/std::sin(.5*pi) << '\n';
}

