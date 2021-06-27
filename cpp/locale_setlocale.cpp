/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_setlocale.exe ./cpp/locale_setlocale.cpp && (cd ../_build/cpp/;./locale_setlocale.exe) || true
https://en.cppreference.com/w/cpp/locale/setlocale
*/
#include <cstdio>
#include <clocale>
#include <ctime>
#include <cwchar>
int main()
{
    // the C locale will be UTF-8 enabled English;
    // decimal dot will be German
    // date and time formatting will be Japanese
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::setlocale(LC_NUMERIC, "de_DE.UTF-8");
    std::setlocale(LC_TIME, "ja_JP.UTF-8");
    wchar_t str[100];
    std::time_t t = std::time(nullptr);
    std::wcsftime(str, 100, L"%A %c", std::localtime(&t));
    std::wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}

