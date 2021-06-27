/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_moneypunct_byname.exe ./cpp/locale_moneypunct_byname.cpp && (cd ../_build/cpp/;./locale_moneypunct_byname.exe)
https://en.cppreference.com/w/cpp/locale/moneypunct_byname
*/
#include <iostream>
#include <iomanip>
#include <locale>
int main()
{
    long double mon = 1234567;
    std::locale::global(std::locale("en_US.utf8"));
    std::wcout.imbue(std::locale());
    std::wcout << L"american locale : " << std::showbase
               << std::put_money(mon) << '\n';
    std::wcout.imbue(std::locale(std::wcout.getloc(),
                                 new std::moneypunct_byname<wchar_t>("ru_RU.utf8")));
    std::wcout << L"american locale with russian moneypunct: "
               << std::put_money(mon) << '\n';
}

