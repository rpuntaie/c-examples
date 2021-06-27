/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_front.exe ./cpp/string_basic_string_view_front.cpp && (cd ../_build/cpp/;./string_basic_string_view_front.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/front
*/
#include <string_view>
#include <iostream>
int main() {
    for (std::string_view str{"ABCDEF"}; !str.empty(); str.remove_prefix(1))
        std::cout << str.front() << ' ' << str << '\n';
}

