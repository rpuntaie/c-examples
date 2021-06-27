/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_function_template_4.exe ./cpp/language_function_template_4.cpp && (cd ../_build/cpp/;./language_function_template_4.exe)
https://en.cppreference.com/w/cpp/language/function_template
*/
#include <iostream>
int main() 
{
    std::cout << "Hello, world" << std::endl;
    // operator<< is looked up via ADL as std::operator<<,
    // then deduced to operator<<<char, std::char_traits<char>> both times
    // std::endl is deduced to &std::endl<char, std::char_traits<char>>
}

