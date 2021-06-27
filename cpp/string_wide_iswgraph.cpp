/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_iswgraph.exe ./cpp/string_wide_iswgraph.cpp && (cd ../_build/cpp/;./string_wide_iswgraph.exe)
https://en.cppreference.com/w/cpp/string/wide/iswgraph
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u2602'; // the Unicode character Umbrella ('☂')
    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswgraph(" << (std::wint_t)c << ") = "
              << (bool)std::iswgraph(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswgraph(" << (std::wint_t)c << ") = "
              << (bool)std::iswgraph(c) << '\n';
}

