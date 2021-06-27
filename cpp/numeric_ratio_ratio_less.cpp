/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_less.exe ./cpp/numeric_ratio_ratio_less.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_less.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_less
*/
#include <iostream>
#include <ratio>
int main()
{
    if (std::ratio_less<std::ratio<23,37>, std::ratio<57,90>>::value) {
        std::cout << "23/37 < 57/90\n";
    }
}

