/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_take_view.exe ./cpp/ranges_take_view.cpp && (cd ../_build/cpp/;./ranges_take_view.exe)
https://en.cppreference.com/w/cpp/ranges/take_view
*/
#include <algorithm>
#include <iostream>
#include <ranges>
auto print = [](char x) { std::cout << x; };
int main()
{
    constexpr char pi[] { '3', '.', '1', '4', '1', '5', '9', '2' };
    std::ranges::for_each(pi | std::ranges::views::take(6), print);
    std::cout << '\n';
    std::ranges::for_each(std::ranges::take_view{pi, 42}, print); // safely takes only 8 chars
    std::cout << '\n';
}

