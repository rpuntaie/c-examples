/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_reverse_copy.exe ./cpp/algorithm_ranges_reverse_copy.cpp && (cd ../_build/cpp/;./algorithm_ranges_reverse_copy.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/reverse_copy
*/
#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    std::string x{"12345"}, y(x.size(), ' ');
    std::cout << x << " → ";
    std::ranges::reverse_copy(x.begin(), x.end(), y.begin());
    std::cout << y << " → ";
    std::ranges::reverse_copy(y, x.begin());
    std::cout << x << '\n';
}

