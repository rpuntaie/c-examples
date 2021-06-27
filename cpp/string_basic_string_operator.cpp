/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_operator.exe ./cpp/string_basic_string_operator.cpp && (cd ../_build/cpp/;./string_basic_string_operator.exe)
https://en.cppreference.com/w/cpp/string/basic_string/operator+
*/
#include <iostream>
#include <string>
int main()
{
    std::string s1 = "Hello";
    std::string s2 = "world";
    std::cout << s1 + ' ' + s2 + "!\n";
}

