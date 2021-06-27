/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_multiply.exe ./cpp/numeric_ratio_ratio_multiply.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_multiply.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_multiply
*/
#include <iostream>
#include <ratio>
int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;
    using product = std::ratio_multiply<two_third, one_sixth>;
    std::cout << "2/3 * 1/6 = " << product::num << '/' << product::den << '\n';
}

