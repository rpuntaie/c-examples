/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_remove_prefix.exe ./cpp/string_basic_string_view_remove_prefix.cpp && (cd ../_build/cpp/;./string_basic_string_view_remove_prefix.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/remove_prefix
*/
#include <iostream>
#include <algorithm>
#include <string_view>
int main()
{
    std::string str = "   trim me";
    std::string_view v = str;
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
    std::cout << "String: '" << str << "'\n"
              << "View  : '" << v << "'\n";
}

