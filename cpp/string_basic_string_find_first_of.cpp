/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_find_first_of.exe ./cpp/string_basic_string_find_first_of.cpp && (cd ../_build/cpp/;./string_basic_string_find_first_of.exe)
https://en.cppreference.com/w/cpp/string/basic_string/find_first_of
*/
#include <iostream>
#include <string>
int main()
{
    // the test string
    std::string str = std::string("Hello World!");
    // strings and chars to search for
    std::string search_str = std::string("o");
    const char* search_cstr = "Good Bye!";
    std::cout << str.find_first_of(search_str) << '\n';
    std::cout << str.find_first_of(search_str, 5) << '\n';
    std::cout << str.find_first_of(search_cstr) << '\n';
    std::cout << str.find_first_of(search_cstr, 0, 4) << '\n';
    // 'x' is not in "Hello World', thus it will return std::string::npos
    std::cout << str.find_first_of('x') << '\n';
}

