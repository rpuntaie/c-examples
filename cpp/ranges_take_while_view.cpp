/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_take_while_view.exe ./cpp/ranges_take_while_view.cpp && (cd ../_build/cpp/;./ranges_take_while_view.exe)
https://en.cppreference.com/w/cpp/ranges/take_while_view
*/
#include <ranges>
#include <iostream>
int main()
{
    for (int year : std::views::iota(2017)
                  | std::views::take_while([](int y) { return y <= 2020; })) {
        std::cout << year << ' ';
    }
    std::cout << '\n';
    const char idea[] {"Today is yesterday's tomorrow!.."};
    for (char x : std::ranges::take_while_view(idea, [](char c) { return c != '.'; })) {
        std::cout << x;
    }
    std::cout << '\n';
}

