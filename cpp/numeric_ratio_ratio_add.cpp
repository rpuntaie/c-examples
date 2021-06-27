/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_add.exe ./cpp/numeric_ratio_ratio_add.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_add.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_add
*/
#include <iostream>
#include <ratio>
int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;
    using sum = std::ratio_add<two_third, one_sixth>;
    std::cout << "2/3 + 1/6 = " << sum::num << '/' << sum::den << '\n';
}

