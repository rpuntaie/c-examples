/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_reverse.exe ./cpp/algorithm_ranges_reverse.cpp && (cd ../_build/cpp/;./algorithm_ranges_reverse.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/reverse
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
int main()
{
    std::string s{"ABCDEF"};
    std::cout << s << " → ";
    std::ranges::reverse(s.begin(), s.end());
    std::cout << s << " → ";
    std::ranges::reverse(s);
    std::cout << s << " │ ";
    std::array a{1, 2, 3, 4, 5};
    for(auto e : a) { std::cout << e << ' '; }
    std::cout << "→ ";
    std::ranges::reverse(a);
    for(auto e : a) { std::cout << e << ' '; }
    std::cout << '\n';
}

