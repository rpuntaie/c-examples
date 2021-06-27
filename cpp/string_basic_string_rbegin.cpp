/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_rbegin.exe ./cpp/string_basic_string_rbegin.cpp && (cd ../_build/cpp/;./string_basic_string_rbegin.exe)
https://en.cppreference.com/w/cpp/string/basic_string/rbegin
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
int main()
{
    std::string s("Exemplar!");
    *s.rbegin() = 'y';
    std::cout << s << '\n'; // "Exemplary"
    std::string c;
    std::copy(s.crbegin(), s.crend(), std::back_inserter(c));
    std::cout << c << '\n'; // "yralpmexE"
}

