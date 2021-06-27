/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_frexp_1.exe ./cpp/numeric_math_frexp_1.cpp && (cd ../_build/cpp/;./numeric_math_frexp_1.exe)
https://en.cppreference.com/w/cpp/numeric/math/frexp
*/
#include <iostream>
#include <cmath>
#include <limits>
int main()
{
    double f = 123.45;
    std::cout << "Given the number " << f << " or " << std::hexfloat
              << f << std::defaultfloat << " in hex,\n";
    double f3;
    double f2 = std::modf(f, &f3);
    std::cout << "modf() makes " << f3 << " + " << f2 << '\n';
    int i;
    f2 = std::frexp(f, &i);
    std::cout << "frexp() makes " << f2 << " * 2^" << i << '\n';
    i = std::ilogb(f);
    std::cout << "logb()/ilogb() make " << f/std::scalbn(1.0, i) << " * "
              << std::numeric_limits<double>::radix
              << "^" << std::ilogb(f) << '\n';
}

