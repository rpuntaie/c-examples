/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_ptr_fun.exe ./cpp/utility_functional_ptr_fun.cpp && (cd ../_build/cpp/;./utility_functional_ptr_fun.exe)
https://en.cppreference.com/w/cpp/utility/functional/ptr_fun
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>
constexpr bool is_vowel(char c)
{
    return std::string_view{"aeoiuAEIOU"}.find(c) != std::string_view::npos;
}
int main()
{
    std::string_view s = "Hello, world!";
    std::ranges::copy_if(s, std::ostreambuf_iterator<char>(std::cout),
        std::not1(std::ptr_fun(is_vowel)));
#if 0
// C++11 alternatives:
        std::not1(std::cref(is_vowel)));
        std::not1(std::function<bool(char)>(is_vowel)));
        [](char c){ return !is_vowel(c); });
// C++17 alternatives:
        std::not_fn(is_vowel));
#endif
}

