/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_towlower.exe ./cpp/string_wide_towlower.cpp && (cd ../_build/cpp/;./string_wide_towlower.exe)
https://en.cppreference.com/w/cpp/string/wide/towlower
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u0190'; // Latin capital open E ('Ɛ')
    std::cout << std::hex << std::showbase;
    std::cout << "in the default locale, towlower(" << (std::wint_t)c << ") = "
              << std::towlower(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, towlower(" << (std::wint_t)c << ") = "
              << std::towlower(c) << '\n';
}

