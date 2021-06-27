/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_wcsrtombs.exe ./cpp/string_multibyte_wcsrtombs.cpp && (cd ../_build/cpp/;./string_multibyte_wcsrtombs.exe)
https://en.cppreference.com/w/cpp/string/multibyte/wcsrtombs
*/
#include <iostream>
#include <vector>
#include <clocale>
#include <string>
#include <cwchar>
void print_wide(const wchar_t* wstr)
{
    std::mbstate_t state = std::mbstate_t();
    std::size_t len = 1 + std::wcsrtombs(nullptr, &wstr, 0, &state);
    std::vector<char> mbstr(len);
    std::wcsrtombs(&mbstr[0], &wstr, mbstr.size(), &state);
    std::cout << "multibyte string: " << &mbstr[0] << '\n'
              << "Length, including '\\0': " << mbstr.size() << '\n';
}
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    // UTF-8 narrow multibyte encoding
    const wchar_t* wstr = L"z\u00df\u6c34\U0001d10b"; // or L"zß水𝄋"
    print_wide(wstr);
}

