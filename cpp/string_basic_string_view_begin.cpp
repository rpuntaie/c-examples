/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_begin.exe ./cpp/string_basic_string_view_begin.cpp && (cd ../_build/cpp/;./string_basic_string_view_begin.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/begin
*/
#include <iostream>
#include <string_view>
#include <type_traits>
int main()
{
    std::string_view str_view("abcd");
    auto begin = str_view.begin();
    auto cbegin = str_view.cbegin();
    std::cout << *begin << '\n';
    std::cout << *cbegin << '\n';
    std::cout << std::boolalpha << (begin == cbegin) << '\n';
    std::cout << std::boolalpha << (*begin == *cbegin) << '\n';
    static_assert(std::is_same<decltype(begin), decltype(cbegin)>{});
}

