/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_iswblank.exe ./cpp/string_wide_iswblank.cpp && (cd ../_build/cpp/;./string_wide_iswblank.exe)
https://en.cppreference.com/w/cpp/string/wide/iswblank
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u3000'; // Ideographic space ('　')
    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswblank(" << (std::wint_t)c << ") = "
              << (bool)std::iswblank(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswblank(" << (std::wint_t)c << ") = "
              << (bool)std::iswblank(c) << '\n';
}

