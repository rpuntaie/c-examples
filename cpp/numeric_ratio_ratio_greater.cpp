/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_greater.exe ./cpp/numeric_ratio_ratio_greater.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_greater.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_greater
*/
#include <ratio>
#include <iostream>
auto main() -> int
{
    static_assert(std::ratio_greater<std::ratio<3, 4>, std::ratio<1, 2>>::value,
                  "3/4 > 1/2");
    if (std::ratio_greater<std::ratio<11, 12>, std::ratio<10, 11>>::value) {
        std::cout << "11/12 > 10/11" "\n";
    }
    // Since C++17
    static_assert(std::ratio_greater_v<std::ratio<12, 13>, std::ratio<11, 12>> );
    if constexpr (std::ratio_greater_v<std::ratio<12, 13>, std::ratio<11, 12>>) {
        std::cout << "12/13 > 11/12" "\n";
    }
}

