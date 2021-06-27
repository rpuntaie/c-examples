/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_in_range.exe ./cpp/utility_in_range.cpp && (cd ../_build/cpp/;./utility_in_range.exe)
https://en.cppreference.com/w/cpp/utility/in_range
*/
#include <utility>
#include <iostream>
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::in_range<std::size_t>(-1) << '\n';
    std::cout << std::in_range<std::size_t>(42) << '\n';
}

