/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_fmod.exe ./c/numeric_math_fmod.c && (cd ../_build/c/;./numeric_math_fmod.exe)
https://en.cppreference.com/w/c/numeric/math/fmod
*/
double fmod(double x, double y)
{
#pragma STDC FENV_ACCESS ON
    double result = remainder(fabs(x), (y = fabs(y)));
    if (signbit(result)) result += y;
    return copysign(result, x);
}

