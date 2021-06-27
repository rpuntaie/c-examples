/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_remove.exe ./cpp/algorithm_remove.cpp && (cd ../_build/cpp/;./algorithm_remove.exe)
https://en.cppreference.com/w/cpp/algorithm/remove
*/
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
int main()
{
    std::string str1 = "Text with some   spaces";
    str1.erase(std::remove(str1.begin(), str1.end(), ' '),
               str1.end());
    std::cout << str1 << '\n';
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(), 
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
    std::cout << str2 << '\n';
}

