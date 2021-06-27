/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_ecmascript_1.exe ./cpp/regex_ecmascript_1.cpp && (cd ../_build/cpp/;./regex_ecmascript_1.exe)
https://en.cppreference.com/w/cpp/regex/ecmascript
*/
#include <iostream>
#include <regex>
// TODO: Convert to wide-accepting
// std::match_results<std::basic_string<_ch>::const_iterator> m; does not work.
void show_matches(const std::string& in, const std::string& re)
{
    std::smatch m;
    std::regex_search(in, m, std::regex(re));
    if(m.empty()) {
        std::cout << "input=[" << in << "], regex=[" << re << "]: NO MATCH\n";
    } else {
        std::cout << "input=[" << in << "], regex=[" << re << "]: ";
        std::cout << "prefix=[" << m.prefix() << "] ";
        for(std::size_t n = 0; n < m.size(); ++n)
            std::cout << " m[" << n << "]=[" << m[n] << "] ";
        std::cout << "suffix=[" << m.suffix() << "]\n";
    }
}
int main()
{
    show_matches("abcdef", ""); // empty regex is a single empty Alternative
    show_matches("abc", "abc|"); // left Alernative matched first
    show_matches("abc", "|abc"); // left Alernative matched first, leaving abc unmatched
}

