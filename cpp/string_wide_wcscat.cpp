/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcscat.exe ./cpp/string_wide_wcscat.cpp && (cd ../_build/cpp/;./string_wide_wcscat.exe)
https://en.cppreference.com/w/cpp/string/wide/wcscat
*/
#include <iostream>
#include <cwchar> 
#include <clocale>
int main(void) 
{
    wchar_t str[50] = L"Земля, прощай.";
    std::wcscat(str, L" ");
    std::wcscat(str, L"В добрый путь.");
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    std::wcout << str << '\n';
}

