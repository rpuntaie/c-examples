/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_bind12.exe ./cpp/utility_functional_bind12.cpp && (cd ../_build/cpp/;./utility_functional_bind12.exe)
https://en.cppreference.com/w/cpp/utility/functional/bind12
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstddef>
#include <vector>
int main()
{
    std::vector<double> a = {0, 30, 45, 60, 90, 180};
    std::vector<double> r(a.size());
    const double pi = std::acos(-1); // since C++20 use std::numbers::pi
    std::transform(a.begin(), a.end(), r.begin(),
        std::bind1st(std::multiplies<double>(), pi / 180.));
//  an equivalent lambda is: [pi](double a){ return a*pi / 180.; });
    for(std::size_t n = 0; n < a.size(); ++n)
        std::cout << std::setw(3) << a[n] << "° = " << std::fixed << r[n]
                  << " rad\n" << std::defaultfloat;
}

