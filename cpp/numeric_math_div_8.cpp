/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_div_8.exe ./cpp/numeric_math_div_8.cpp && (cd ../_build/cpp/;./numeric_math_div_8.exe)
https://en.cppreference.com/w/cpp/numeric/math/div
*/
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
std::string itoa(int n, int base /*[2..16]*/)
{
    std::string buf;
    std::div_t dv{}; dv.quot = n;
    do {
        dv = std::div(dv.quot, base);
        buf += "0123456789abcdef"[std::abs(dv.rem)];  // string literals are arrays
    } while(dv.quot);
    if(n<0) buf += '-';
    return {buf.rbegin(), buf.rend()};
}
int main()
{
    std::cout << itoa(12345, 10) << '\n'
              << itoa(-12345, 10) << '\n'
              << itoa(42, 2) << '\n'
              << itoa(65535, 16) << '\n';
}

