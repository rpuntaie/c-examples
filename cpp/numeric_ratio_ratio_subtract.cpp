/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_subtract.exe ./cpp/numeric_ratio_ratio_subtract.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_subtract.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_subtract
*/
#include <iostream>
#include <ratio>
int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;
    using diff = std::ratio_subtract<two_third, one_sixth>;
    std::cout << "2/3 - 1/6 = " << diff::num << '/' << diff::den << '\n';
}

