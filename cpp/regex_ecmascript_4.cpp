/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_ecmascript_4.exe ./cpp/regex_ecmascript_4.cpp && (cd ../_build/cpp/;./regex_ecmascript_4.exe)
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
    // Most escapes are similar to C++, save for metacharacters. You will have to
    // double-escape or use raw strings on the slashes though.
    show_matches("C++\\", R"(C\+\+\\)");
    // Escape sequences and NUL.
    std::string s("ab\xff\0cd", 5);
    show_matches(s, "(\\0|\\u00ff)");
    // No matching for non-BMP Unicode is defined, because ECMAScript uses UTF-16
    // atoms. Whether this emoji banana matches can be platform dependent:
    // XXX: These need to be wide-strings!
    // show_matches(L"\U0001f34c", L"[\\u0000-\\ufffe]+");
}

