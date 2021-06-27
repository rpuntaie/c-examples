/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_toupper.exe ./cpp/locale_toupper.cpp && (cd ../_build/cpp/;./locale_toupper.exe)
https://en.cppreference.com/w/cpp/locale/toupper
*/
#include <iostream>
#include <cwctype>
#include <locale>
int main()
{
    wchar_t c = L'\u017f'; // Latin small letter Long S ('ſ')
    std::cout << std::hex << std::showbase;
    std::cout << "in the default locale, toupper(" << (std::wint_t)c << ") = "
              << std::toupper(c, std::locale()) << '\n';
    std::cout << "in Unicode locale, toupper(" << (std::wint_t)c << ") = "
              << std::toupper(c, std::locale("en_US.utf8")) << '\n';
}

