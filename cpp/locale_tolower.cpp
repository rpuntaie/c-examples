/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_tolower.exe ./cpp/locale_tolower.cpp && (cd ../_build/cpp/;./locale_tolower.exe)
https://en.cppreference.com/w/cpp/locale/tolower
*/
#include <iostream>
#include <cwctype>
#include <locale>
int main()
{
    wchar_t c = L'\u0190'; // Latin capital open E ('Ɛ')
    std::cout << std::hex << std::showbase;
    std::cout << "in the default locale, tolower(" << (std::wint_t)c << ") = "
              << std::tolower(c, std::locale()) << '\n';
    std::cout << "in Unicode locale, tolower(" << (std::wint_t)c << ") = "
              << std::tolower(c, std::locale("en_US.utf8")) << '\n';
}

