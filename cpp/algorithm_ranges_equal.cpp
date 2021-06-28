/*
# g++ --std=c++23 -pthread -o ../_build/cpp/algorithm_ranges_equal.exe ./cpp/algorithm_ranges_equal.cpp && (cd ../_build/cpp/;./algorithm_ranges_equal.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/equal
*/
#include <algorithm>
#include <iostream>
#include <string_view>
#include <ranges>
constexpr bool is_palindrome(const std::string_view s)
{
    namespace views = std::views;
    auto forward = s | views::take(s.size() / 2);
    auto backward = s | views::reverse | views::take(s.size() / 2);
    return std::ranges::equal(forward, backward);
}
void test(const std::string_view s)
{
    std::cout << "\"" << s << "\" is"
        << (is_palindrome(s) ? "" : " not")
        << " a palindrome\n";
}
int main()
{
    test("radar");
    test("hello");
}

