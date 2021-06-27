/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_ellint_3.exe ./cpp/numeric_special_functions_ellint_3.cpp && (cd ../_build/cpp/;./numeric_special_functions_ellint_3.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3
*/
#include <cmath>
#include <iostream>
int main()
{
    double hpi = std::acos(-1)/2;
    std::cout << "Π(0,0,π/2) = " << std::ellint_3(0, 0, hpi) << '\n'
              << "π/2 = " << hpi << '\n';
}

