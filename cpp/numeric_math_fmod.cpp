/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_fmod.exe ./cpp/numeric_math_fmod.cpp && (cd ../_build/cpp/;./numeric_math_fmod.exe)
https://en.cppreference.com/w/cpp/numeric/math/fmod
*/
double fmod(double x, double y)
{
#pragma STDC FENV_ACCESS ON
    double result = std::remainder(std::fabs(x), (y = std::fabs(y)));
    if (std::signbit(result)) result += y;
    return std::copysign(result, x);
}

