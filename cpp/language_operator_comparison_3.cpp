/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_comparison_3.exe ./cpp/language_operator_comparison_3.cpp && (cd ../_build/cpp/;./language_operator_comparison_3.exe)
https://en.cppreference.com/w/cpp/language/operator_comparison
*/
#include <iostream>
int main() {
    int a = 3, b = 2, c = 1;
    std::cout << std::boolalpha
        << ( a < b < c ) << '\n' // true; maybe warning
        << ( ( a < b ) < c ) << '\n' // true
        << ( a < ( b < c ) ) << '\n' // false
        << ( ( a < b ) && ( b < c ) ) << '\n'; // false
}

