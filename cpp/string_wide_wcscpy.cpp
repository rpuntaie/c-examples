/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcscpy.exe ./cpp/string_wide_wcscpy.cpp && (cd ../_build/cpp/;./string_wide_wcscpy.exe)
https://en.cppreference.com/w/cpp/string/wide/wcscpy
*/
#include <iostream>
#include <cwchar>
#include <memory>
#include <clocale>
int main()
{
    const wchar_t* src = L"犬 means dog";
//  src[0] = L'狗'; // can't modify string literal
    auto dst = std::make_unique<wchar_t[]>(std::wcslen(src)+1); // +1 for the null
    std::wcscpy(dst.get(), src);
    dst[0] = L'狗';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale(""));
    std::wcout << src << '\n' << dst.get() << '\n';
}

