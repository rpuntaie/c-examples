/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_syntax_option_type.exe ./cpp/regex_syntax_option_type.cpp && (cd ../_build/cpp/;./regex_syntax_option_type.exe)
https://en.cppreference.com/w/cpp/regex/syntax_option_type
*/
#include <iostream>
#include <string>
#include <regex>
int main()
{
    std::string str = "zzxayyzz";
    std::regex re1(".*(a|xayy)"); // ECMA
    std::regex re2(".*(a|xayy)", std::regex::extended); // POSIX
    std::cout << "Searching for .*(a|xayy) in zzxayyzz:\n";
    std::smatch m;
    std::regex_search(str, m, re1);
    std::cout << " ECMA (depth first search) match: " << m[0] << '\n';
    std::regex_search(str, m, re2);
    std::cout << " POSIX (leftmost longest)  match: " << m[0] << '\n';
}

