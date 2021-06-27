/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wmemcpy.exe ./cpp/string_wide_wmemcpy.cpp && (cd ../_build/cpp/;./string_wide_wmemcpy.exe)
https://en.cppreference.com/w/cpp/string/wide/wmemcpy
*/
#include <iostream>
#include <cwchar>
#include <clocale>
#include <locale>
int main(void)
{
    wchar_t from1[] = L"नमस्ते";
    const size_t sz1 = sizeof from1 / sizeof *from1;
    wchar_t from2[] = L"Բարև";
    const size_t sz2 = sizeof from2 / sizeof *from2;
    wchar_t to[sz1 + sz2];
    std::wmemcpy(to, from1, sz1); // copy from1, along with its null terminator
    std::wmemcpy(to + sz1, from2, sz2); // append from2, along with its null terminator
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout.imbue(std::locale("en_US.utf8"));
    std::wcout << "Wide array contains: ";
    for(size_t n = 0; n < sizeof to / sizeof *to; ++n)
        if(to[n])
            std::wcout << to[n];
        else
            std::wcout << "\\0";
    std::wcout << '\n';
}

