/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_ecmascript.exe ./cpp/regex_ecmascript.cpp && (cd ../_build/cpp/;./regex_ecmascript.exe)
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
    show_matches("abcdef", "abc|def");
    show_matches("abc", "ab|abc"); // left Alernative matched first
    // Match of the input against the left Alternative (a) followed
    // by the remained of the regex (c|bc) succeeds, which results
    // in m[1]="a" and m[4]="bc".
    // The skipped Alternatives (ab) and (c) leave their submatches
    // m[3] and m[5] empty.
    show_matches("abc", "((a)|(ab))((c)|(bc))");
}

