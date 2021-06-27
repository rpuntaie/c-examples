/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_starts_with.exe ./cpp/algorithm_ranges_starts_with.cpp && (cd ../_build/cpp/;./algorithm_ranges_starts_with.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/starts_with
*/
#include <string_view>
#include <algorithm>
#include <iostream>
#include <ranges>
int main()
{
    using namespace std::literals;
    constexpr auto ascii_upper = [](char8_t c)
    {
        return u8'a' <= c && c <= u8'z' ? static_cast<char8_t>(c + u8'A' - u8'a') : c;
    };
    constexpr auto cmp_ignore_case = [=](char8_t x, char8_t y)
    {
        return ascii_upper(x) == ascii_upper(y);
    };
    static_assert(std::ranges::starts_with("const_cast", "const"sv));
    static_assert(std::ranges::starts_with("constexpr", "const"sv));
    static_assert(!std::ranges::starts_with("volatile", "const"sv));
    std::cout
        << std::boolalpha
        << std::ranges::starts_with(u8"Constantinopolis", u8"constant"sv,
                                    {}, ascii_upper, ascii_upper) << ' '
        << std::ranges::starts_with(u8"Istanbul", u8"constant"sv,
                                    {}, ascii_upper, ascii_upper) << ' '
        << std::ranges::starts_with(u8"Metropolis", u8"metro"sv,
                                    cmp_ignore_case) << ' '
        << std::ranges::starts_with(u8"Acropolis", u8"metro"sv,
                                    cmp_ignore_case) << '\n';
    constexpr static auto v = { 1, 3, 5, 7, 9 };
    constexpr auto odd = [](int x) { return x % 2; };
    static_assert( std::ranges::starts_with( v, std::views::iota(1)
                                              | std::views::filter(odd)
                                              | std::views::take(3) ) );
}

