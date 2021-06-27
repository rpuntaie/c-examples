/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_swap.exe ./cpp/string_basic_string_view_swap.cpp && (cd ../_build/cpp/;./string_basic_string_view_swap.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/swap
*/
#include <string_view>
#include <iostream>
int main() {
    auto s1{ std::string_view{"⏺⏺⏺⏺⏺"} };
    auto s2{ std::string_view{"⏹⏹⏹⏹⏹"} };
    std::cout << "Before : " << s1 << ' ' << s2 << "\n";
    s1.swap(s2);
    std::cout << "After  : " << s1 << ' ' << s2 << "\n";
}

