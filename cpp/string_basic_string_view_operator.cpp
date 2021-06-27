/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_operator.exe ./cpp/string_basic_string_view_operator.cpp && (cd ../_build/cpp/;./string_basic_string_view_operator.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/operator=
*/
#include <iostream>
#include <string_view>
int main()
{
    std::string_view v = "Hello, world";
    v = v.substr(7);
    std::cout << v << '\n';
}

