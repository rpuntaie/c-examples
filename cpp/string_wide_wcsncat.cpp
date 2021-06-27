/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcsncat.exe ./cpp/string_wide_wcsncat.cpp && (cd ../_build/cpp/;./string_wide_wcsncat.exe)
https://en.cppreference.com/w/cpp/string/wide/wcsncat
*/
#include <cwchar> 
#include <iostream>
#include <clocale>
int main(void) 
{
    wchar_t str[50] = L"Земля, прощай.";
    std::wcsncat(str, L" ", 1);
    std::wcsncat(str, L"В добрый путь.", 8); // only append the first 8 wide chars
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    std::wcout << str << '\n';
}

