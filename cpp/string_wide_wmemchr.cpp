/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wmemchr.exe ./cpp/string_wide_wmemchr.cpp && (cd ../_build/cpp/;./string_wide_wmemchr.exe)
https://en.cppreference.com/w/cpp/string/wide/wmemchr
*/
#include <iostream>
#include <cwchar>
#include <clocale>
#include <locale>
int main()
{
    const wchar_t str[] = L"诺不轻信，故人不负我\0诺不轻许，故我不负人。";
    wchar_t target = L'许';
    const std::size_t sz = sizeof str / sizeof *str;
    if (const wchar_t* result = std::wmemchr(str, target, sz)) {
        std::setlocale(LC_ALL, "en_US.utf8");
        std::wcout.imbue(std::locale("en_US.utf8"));
        std::wcout << "Found '" << target
                   << "' at position " << result - str << "\n";
    }
}

