/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_remquo.exe ./cpp/numeric_math_remquo.cpp && (cd ../_build/cpp/;./numeric_math_remquo.exe)
https://en.cppreference.com/w/cpp/numeric/math/remquo
*/
#include <iostream>
#include <cmath>
#include <cfenv>
#ifndef __GNUC__
#pragma STDC FENV_ACCESS ON
#endif
constexpr double pi = std::acos(-1); // C++20: std::numbers::pi
double cos_pi_x_naive(double x) { return std::cos(pi * x); }
// the period is 2, values are (0;0.5) positive, (0.5;1.5) negative, (1.5,2) positive
double cos_pi_x_smart(double x)
{
    int quadrant;
    double rem = std::remquo(x, 1, &quadrant);
    quadrant = static_cast<unsigned>(quadrant) % 2;  // The period is 2.
    return quadrant == 0 ?  std::cos(pi * rem)
                         :- std::cos(pi * rem);
}
int main()
{
    std::cout << std::showpos
              << "naive:\n"
              << "  cos(pi * 0.25) = " << cos_pi_x_naive(0.25) << '\n'
              << "  cos(pi * 1.25) = " << cos_pi_x_naive(1.25) << '\n'
              << "  cos(pi * 2.25) = " << cos_pi_x_naive(2.25) << '\n'
              << "smart:\n"
              << "  cos(pi * 0.25) = " << cos_pi_x_smart(0.25) << '\n'
              << "  cos(pi * 1.25) = " << cos_pi_x_smart(1.25) << '\n'
              << "  cos(pi * 2.25) = " << cos_pi_x_smart(2.25) << '\n'
              << "naive:\n"
              << "  cos(pi * 1000000000000.25) = "
              << cos_pi_x_naive(1000000000000.25) << '\n'
              << "  cos(pi * 1000000000001.25) = "
              << cos_pi_x_naive(1000000000001.25) << '\n'
              << "smart:\n"
              << "  cos(pi * 1000000000000.25) = "
              << cos_pi_x_smart(1000000000000.25) << '\n'
              << "  cos(pi * 1000000000001.25) = "
              << cos_pi_x_smart(1000000000001.25) << '\n';
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    int quo;
    std::cout << "remquo(+Inf, 1) = " << std::remquo(INFINITY, 1, &quo) << '\n';
    if(fetestexcept(FE_INVALID)) std::cout << "  FE_INVALID raised\n";
}

