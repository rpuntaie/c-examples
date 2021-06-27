/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_numpunct_byname.exe ./cpp/locale_numpunct_byname.cpp && (cd ../_build/cpp/;./locale_numpunct_byname.exe)
https://en.cppreference.com/w/cpp/locale/numpunct_byname
*/
#include <iostream>
#include <locale>
int main()
{
    const double number = 1000.25;
    std::wcout << L"default locale: " << number << L'\n';
    std::wcout.imbue(std::locale(std::wcout.getloc(),
                                 new std::numpunct_byname<wchar_t>("ru_RU.UTF8")));
    std::wcout << L"default locale with russian numpunct: " << number << L'\n';
}

