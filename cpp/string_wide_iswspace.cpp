/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_iswspace.exe ./cpp/string_wide_iswspace.cpp && (cd ../_build/cpp/;./string_wide_iswspace.exe)
https://en.cppreference.com/w/cpp/string/wide/iswspace
*/
#include <iostream>
#include <clocale>
#include <cwctype>
void try_with(wchar_t c, const char* loc)
{
    std::setlocale(LC_ALL, loc);
    std::wcout << "isspace('" << c << "') in " << loc << " locale returned "
               << std::boolalpha << (bool)std::iswspace(c) << '\n';
}
int main()
{
    wchar_t EM_SPACE = L'\u2003'; // Unicode character 'EM SPACE'
    try_with(EM_SPACE, "C");
    try_with(EM_SPACE, "en_US.UTF8");
}

