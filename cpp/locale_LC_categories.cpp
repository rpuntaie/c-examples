/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_LC_categories.exe ./cpp/locale_LC_categories.cpp && (cd ../_build/cpp/;./locale_LC_categories.exe) || true
https://en.cppreference.com/w/cpp/locale/LC_categories
*/
#include <cstdio>
#include <clocale>
#include <ctime>
#include <cwchar>
int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8"); // the C locale will be the UTF-8 enabled English
    std::setlocale(LC_NUMERIC, "de_DE.UTF-8");   // decimal dot will be German
    std::setlocale(LC_TIME, "ja_JP.UTF-8");      // date/time formatting will be Japanese
    wchar_t str[100];
    std::time_t t = std::time(nullptr);
    std::wcsftime(str, 100, L"%A %c", std::localtime(&t));
    std::wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}

