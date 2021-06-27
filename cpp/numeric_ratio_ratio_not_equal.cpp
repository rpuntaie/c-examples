/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_not_equal.exe ./cpp/numeric_ratio_ratio_not_equal.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_not_equal.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_not_equal
*/
#include <iostream>
#include <ratio>
int main()
{
    if(std::ratio_not_equal<std::ratio<2,3>, std::ratio<1,3>>::value) {
        std::cout << "2/3 != 1/3\n";
    } else {
        std::cout << "2/3 == 1/3\n";
    }
}

