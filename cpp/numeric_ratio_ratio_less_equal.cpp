/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_ratio_ratio_less_equal.exe ./cpp/numeric_ratio_ratio_less_equal.cpp && (cd ../_build/cpp/;./numeric_ratio_ratio_less_equal.exe)
https://en.cppreference.com/w/cpp/numeric/ratio/ratio_less_equal
*/
#include <ratio>
#include <iostream>
auto main() -> int
{
    static_assert(std::ratio_less_equal<std::ratio<1, 2>, std::ratio<3, 4>>::value,
                  "1/2 <= 3/4");
    if (std::ratio_less_equal<std::ratio<10,11>, std::ratio<11,12>>::value) {
        std::cout << "10/11 <= 11/12" "\n";
    }
    // Since C++17
    static_assert(std::ratio_less_equal_v<std::ratio<10, 11>, std::ratio<11, 12>> );
    if constexpr (std::ratio_less_equal_v<std::ratio<10, 11>, std::ratio<11, 12>>) {
        std::cout << "11/12 <= 12/13" "\n";
    }
}

