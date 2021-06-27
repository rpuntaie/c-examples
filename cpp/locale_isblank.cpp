/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_isblank.exe ./cpp/locale_isblank.cpp && (cd ../_build/cpp/;./locale_isblank.exe)
https://en.cppreference.com/w/cpp/locale/isblank
*/
#include <iostream>
#include <locale>
void try_with(wchar_t c, const char* loc)
{
    std::wcout << "isblank('" << c << "', locale(\"" << loc << "\")) returned " << std::boolalpha
               << std::isblank(c, std::locale(loc)) << '\n';
}
int main()
{
    const wchar_t IDEO_SPACE = L'\u3000'; // Unicode character 'IDEOGRAPHIC SPACE'
    try_with(IDEO_SPACE, "C");
    try_with(IDEO_SPACE, "en_US.UTF-8");
}

