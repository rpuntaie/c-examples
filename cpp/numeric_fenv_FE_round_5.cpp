/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_fenv_FE_round_5.exe ./cpp/numeric_fenv_FE_round_5.cpp && (cd ../_build/cpp/;./numeric_fenv_FE_round_5.exe)
https://en.cppreference.com/w/cpp/numeric/fenv/FE_round
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cfenv>
#include <cmath>
int main()
{
#pragma STDC FENV_ACCESS ON
    std::fesetround(FE_DOWNWARD);
    std::cout << "rounding down: \n" << std::setprecision(50)
              << "         pi = " << std::acos(-1.f) << '\n'
              << "stof(\"1.1\") = " << std::stof("1.1") << '\n'
              << "  rint(2.1) = " << std::rint(2.1) << "\n\n";
    std::fesetround(FE_UPWARD);
    std::cout << "rounding up: \n"
              << "         pi = " << std::acos(-1.f) << '\n'
              << "stof(\"1.1\") = " << std::stof("1.1") << '\n'
              << "  rint(2.1) = " << std::rint(2.1) << '\n';
}

