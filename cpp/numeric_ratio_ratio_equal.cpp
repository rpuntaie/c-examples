/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_equal.exe ./cpp/numeric_ratio_ratio_equal.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_equal.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_equal
*/
#include <iostream>
#include <ratio>
int main()
{
    if(std::ratio_equal<std::ratio<2,3>, std::ratio<4,6>>::value) {
        std::cout << "2/3 == 4/6\n";
    } else {
        std::cout << "2/3 != 4/6\n";
    }
}

