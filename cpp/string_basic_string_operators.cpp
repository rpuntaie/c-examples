/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_operators.exe ./cpp/string_basic_string_operators.cpp && (cd ../_build/cpp/;./string_basic_string_operators.exe)
https://en.cppreference.com/w/cpp/string/basic_string/operator""s
*/
#include <string>
#include <iostream>
int main()
{
    using namespace std::string_literals;
    std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    std::cout << "s1: " << s1.size() << ' ' << s1 << '\n'
              << "s2: " << s2.size() << ' ' << s2 << '\n'
              << "abcdef"s.substr(1,4) << '\n';
}

