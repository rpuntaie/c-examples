/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_arithmetic_2.exe ./cpp/language_operator_arithmetic_2.cpp && (cd ../_build/cpp/;./language_operator_arithmetic_2.exe)
https://en.cppreference.com/w/cpp/language/operator_arithmetic
*/
#include <iostream>
int main()
{
    char c = 2;
    unsigned int un = 2;
    int  n = -10;
    std::cout <<  "2 * (-10), where 2 is a char    = " << c * n << '\n'
              <<  "2 * (-10), where 2 is unsigned  = " << un * n << '\n'
              <<  "-10 / 2.12  = " << n / 2.12 << '\n'
              <<  "-10 / 21  = " << n / 21 << '\n'
              <<  "-10 % 21  = " << n % 21 << '\n';
}

