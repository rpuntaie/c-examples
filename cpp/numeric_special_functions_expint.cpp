/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_expint.exe ./cpp/numeric_special_functions_expint.cpp && (cd ../_build/cpp/;./numeric_special_functions_expint.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/expint
*/
#include <cmath>
#include <iostream>
int main()
{
    std::cout << "Ei(0) = " << std::expint(0) << '\n'
              << "Ei(1) = " << std::expint(1) << '\n'
              << "Gompetz constant = " << -std::exp(1)*std::expint(-1) << '\n';
}

