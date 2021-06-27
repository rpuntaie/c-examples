/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_back.exe ./cpp/string_basic_string_view_back.cpp && (cd ../_build/cpp/;./string_basic_string_view_back.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/back
*/
#include <string_view>
#include <iostream>
int main() {
    for (std::string_view str{"ABCDEF"}; !str.empty(); str.remove_suffix(1))
        std::cout << str.back() << ' ' << str << '\n';
}

