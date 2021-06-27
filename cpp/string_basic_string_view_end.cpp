/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_end.exe ./cpp/string_basic_string_view_end.cpp && (cd ../_build/cpp/;./string_basic_string_view_end.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/end
*/
#include <iostream>
#include <iterator>
#include <string_view>
int main()
{
    std::string_view str_view("abcd");
    auto end = str_view.end();
    auto cend = str_view.cend();
    std::cout << *std::prev(end) << '\n';
    std::cout << *std::prev(cend) << '\n';
    std::cout << std::boolalpha << (end == cend) << '\n';
}

