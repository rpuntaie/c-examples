/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_begin.exe ./cpp/string_basic_string_begin.cpp && (cd ../_build/cpp/;./string_basic_string_begin.exe)
https://en.cppreference.com/w/cpp/string/basic_string/begin
*/
#include <string>
#include <iostream>
int main()
{
    std::string s("Exemplar");
    *s.begin() = 'e';
    std::cout << s <<'\n';
    auto i = s.cbegin();
    std::cout << *i << '\n';
//  *i = 'E'; // error: i is a constant iterator
}

