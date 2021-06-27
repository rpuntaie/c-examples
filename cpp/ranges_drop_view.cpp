/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_drop_view.exe ./cpp/ranges_drop_view.cpp && (cd ../_build/cpp/;./ranges_drop_view.exe)
https://en.cppreference.com/w/cpp/ranges/drop_view
*/
#include <ranges>
#include <iostream>
int main()
{
    const auto nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i : nums | std::views::drop(2))
        std::cout << i << ' ';
    std::cout << '\n';
    for (int i : std::views::iota(1, 10) | std::views::drop(2))
        std::cout << i << ' ';
    std::cout << '\n';
    for (int i : std::ranges::drop_view{nums, 2})
        std::cout << i << ' ';
    std::cout << '\n';
}

