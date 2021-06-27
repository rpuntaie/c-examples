/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_comp_ellint_2.exe ./cpp/numeric_special_functions_comp_ellint_2.cpp && (cd ../_build/cpp/;./numeric_special_functions_comp_ellint_2.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2
*/
#include <cmath>
#include <iostream>
int main()
{
    double hpi = std::acos(-1)/2;
    std::cout << "E(0) = " << std::comp_ellint_2(0) << '\n'
              << "π/2 = " << hpi << '\n'
              << "E(1) = " << std::comp_ellint_2(1) << '\n'
              << "E(1, π/2) = " << std::ellint_2(1, hpi) << '\n';
}

