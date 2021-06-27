/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_localeconv.exe ./cpp/locale_localeconv.cpp && (cd ../_build/cpp/;./locale_localeconv.exe) || true
https://en.cppreference.com/w/cpp/locale/localeconv
*/
#include <clocale>
#include <iostream>
int main()
{
    std::setlocale(LC_ALL, "ja_JP.UTF-8");
    std::lconv* lc = std::localeconv();
    std::cout << "Japanese currency symbol: " << lc->currency_symbol
              << '(' << lc->int_curr_symbol << ")\n";
}

