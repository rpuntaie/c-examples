/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_iswcntrl.exe ./cpp/string_wide_iswcntrl.cpp && (cd ../_build/cpp/;./string_wide_iswcntrl.exe)
https://en.cppreference.com/w/cpp/string/wide/iswcntrl
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u2028'; // the Unicode character "line separator" 
    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswcntrl(" << (std::wint_t)c << ") = "
              << (bool)std::iswcntrl(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswcntrl(" << (std::wint_t)c << ") = "
              << (bool)std::iswcntrl(c) << '\n';
}

