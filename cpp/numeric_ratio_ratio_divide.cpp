/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_divide.exe ./cpp/numeric_ratio_ratio_divide.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_divide.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_divide
*/
#include <iostream>
#include <ratio>
int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;
    using quotient = std::ratio_divide<two_third, one_sixth>;
    std::cout << "(2/3) / (1/6) = " << quotient::num << '/' << quotient::den << '\n';
}

