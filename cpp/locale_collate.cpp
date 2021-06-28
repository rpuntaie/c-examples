/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_collate.exe ./cpp/locale_collate.cpp && (cd ../_build/cpp/;./locale_collate.exe) || true
https://en.cppreference.com/w/cpp/locale/collate
*/
#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::wcout.imbue(std::locale(""));
    std::vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                   L"\u00e5r", L"f\u00f6rnamn"};
    std::wcout << "Default locale collation order: ";
    std::sort(v.begin(), v.end());
    for (auto s : v) std::wcout << s << ' '; std::wcout << '\n';
    std::wcout << "English locale collation order: ";
    std::sort(v.begin(), v.end(), std::locale("en_US.UTF-8"));
    for (auto s : v) std::wcout << s << ' '; std::wcout << '\n';
    std::wcout << "Swedish locale collation order: ";
    std::sort(v.begin(), v.end(), std::locale("sv_SE.UTF-8"));
    for (auto s : v) std::wcout << s << ' '; std::wcout << '\n';
}

