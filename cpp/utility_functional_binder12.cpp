/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_binder12.exe ./cpp/utility_functional_binder12.cpp && (cd ../_build/cpp/;./utility_functional_binder12.exe)
https://en.cppreference.com/w/cpp/utility/functional/binder12
*/
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
const double pi = std::acos(-1);
int main()
{
    // deprecated in C++11, removed in C++17
    std::binder1st<std::multiplies<double>> f1 = std::bind1st(
                                                   std::multiplies<double>(), pi / 180.);
    // C++11 replacement
    auto f2 = [](double a){ return a*pi/180.; };
    for(double n : {0, 30, 45, 60, 90, 180})
        std::cout << n << "° = " << f1(n) << " rad (using binder) "
                                 << f2(n) << " rad (using lambda)\n";
}

