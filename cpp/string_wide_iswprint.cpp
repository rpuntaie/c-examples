/*
g++ --std=c++17 -pthread -o ../_build/cpp/string_wide_iswprint.exe ./cpp/string_wide_iswprint.cpp && (cd ../_build/cpp/;./string_wide_iswprint.exe)
https://en.cppreference.com/w/cpp/string/wide/iswprint
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u2002'; // en-space
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << std::boolalpha << std::hex << std::showbase
              << "in Unicode locale,\n"
              << "iswprint('" << c << "') = "
              << (bool)std::iswprint(c) << '\n';
    c = L'\u0082'; // break permitted
    std::cout << "iswprint('" << c << "') = "
              << (bool)std::iswprint(c) << '\n';
}

