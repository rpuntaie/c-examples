/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcstol.exe ./cpp/string_wide_wcstol.cpp && (cd ../_build/cpp/;./string_wide_wcstol.exe)
https://en.cppreference.com/w/cpp/string/wide/wcstol
*/
#include <iostream>
#include <string>
#include <errno.h>
#include <cwchar>
int main()
{
    const wchar_t* p = L"10 200000000000000000000000000000 30 -40";
    wchar_t *end;
    std::wcout << "Parsing L'" << p << "':\n";
    for (long i = std::wcstol(p, &end, 10);
         p != end;
         i = std::wcstol(p, &end, 10))
    {
        std::wcout << "'" << std::wstring(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::wcout << "range error, got ";
            errno = 0;
        }
        std::wcout << i << '\n';
    }
}

