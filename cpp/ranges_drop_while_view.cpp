/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_drop_while_view.exe ./cpp/ranges_drop_while_view.cpp && (cd ../_build/cpp/;./ranges_drop_while_view.exe)
https://en.cppreference.com/w/cpp/ranges/drop_while_view
*/
#include <cctype>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
std::string trim(std::string_view const in)
{
    auto view
        = in
        | std::views::drop_while(isspace)
        | std::views::reverse
        | std::views::drop_while(isspace)
        | std::views::reverse
        ;
    return {view.begin(), view.end()};
}
int main()
{
    const auto s = trim(" \f\n\t\r\vHello, C++20!\f\n\t\r\v ");
    std::cout << std::quoted(s) << '\n';
    static constexpr auto v = {0, 1, 2, 3, 4, 5};
    for (int n : v | std::views::drop_while([](int i) { return i < 3; })) {
        std::cout << n << ' ';
    }
}

