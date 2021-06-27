/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_iswupper.exe ./cpp/string_wide_iswupper.cpp && (cd ../_build/cpp/;./string_wide_iswupper.exe)
https://en.cppreference.com/w/cpp/string/wide/iswupper
*/
#include <iostream>
#include <cwctype>
#include <clocale>
int main()
{
    wchar_t c = L'\u053d'; // Armenian capital letter xeh ('Խ')
    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswupper(" << (std::wint_t)c << ") = "
              << (bool)std::iswupper(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswupper(" << (std::wint_t)c << ") = "
              << (bool)std::iswupper(c) << '\n';
}

