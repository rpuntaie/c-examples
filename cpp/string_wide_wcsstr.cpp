/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcsstr.exe ./cpp/string_wide_wcsstr.cpp && (cd ../_build/cpp/;./string_wide_wcsstr.exe)
https://en.cppreference.com/w/cpp/string/wide/wcsstr
*/
#include <iostream>
#include <cwchar>
#include <clocale>
int main()
{
    wchar_t const* origin = L"アルファ, ベータ, ガンマ, アルファ, ベータ, ガンマ.";
    wchar_t const* target = L"ベータ";
    wchar_t const* result = origin;
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout << L"Substring to find: \"" << target << L"\"\n"
               << L"String to search: \"" << origin << L"\"\n\n";
    for (; (result = std::wcsstr(result, target)) != nullptr; ++result)
        std::wcout << L"Found: \"" << result << L"\"\n";
}

