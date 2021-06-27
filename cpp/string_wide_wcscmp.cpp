/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcscmp.exe ./cpp/string_wide_wcscmp.cpp && (cd ../_build/cpp/;./string_wide_wcscmp.exe)
https://en.cppreference.com/w/cpp/string/wide/wcscmp
*/
#include <vector>
#include <cwchar>
#include <algorithm>
#include <iostream>
int main()
{
    std::vector<const wchar_t*> leaders{L"Ленин", L"Сталин", L"Маленков",
        L"Хрущёв", L"Брежнев", L"Андропов", L"Черненко", L"Горбачёв"};
    std::sort(leaders.begin(), leaders.end(), [](auto strA, auto strB) {
        return std::wcscmp(strA, strB) < 0;
    });
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    for (auto leader : leaders)
        std::wcout << leader << '\n';
}

