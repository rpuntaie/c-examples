/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_iota_view.exe ./cpp/ranges_iota_view.cpp && (cd ../_build/cpp/;./ranges_iota_view.exe)
https://en.cppreference.com/w/cpp/ranges/iota_view
*/
#include <ranges>
#include <iostream>
int main()
{
    for (int i : std::ranges::iota_view{1, 10})
        std::cout << i << ' ';
    std::cout << '\n';
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';
    for (int i : std::views::iota(1) | std::views::take(9))
        std::cout << i << ' ';
    std::cout << '\n';
}

