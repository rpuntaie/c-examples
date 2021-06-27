/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcstof.exe ./cpp/string_wide_wcstof.cpp && (cd ../_build/cpp/;./string_wide_wcstof.exe)
https://en.cppreference.com/w/cpp/string/wide/wcstof
*/
#include <iostream>
#include <string>
#include <cerrno>
#include <cwchar>
int main()
{
    const wchar_t* p = L"111.11 -2.22 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
    wchar_t* end;
    std::wcout << "Parsing L\"" << p << "\":\n";
    for (double f = std::wcstod(p, &end); p != end; f = std::wcstod(p, &end))
    {
        std::wcout << "'" << std::wstring(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::wcout << "range error, got ";
            errno = 0;
        }
        std::wcout << f << '\n';
    }
}

