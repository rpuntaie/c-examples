/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_wctomb.exe ./cpp/string_multibyte_wctomb.cpp && (cd ../_build/cpp/;./string_multibyte_wctomb.exe)
https://en.cppreference.com/w/cpp/string/multibyte/wctomb
*/
#include <iostream>
#include <clocale>
#include <string>
#include <cstdlib>
void print_wide(const std::wstring& wstr)
{
    bool shifts = std::wctomb(nullptr, 0); // reset the conversion state
    std::cout << "shift sequences " << (shifts ? "are" : "not" ) << " used\n";
    for (wchar_t wc : wstr) {
        std::string mb(MB_CUR_MAX, '\0');
        int ret = std::wctomb(&mb[0], wc);
        std::cout << "multibyte char " << mb << " is " << ret << " bytes\n";
    }
}
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    // UTF-8 narrow multibyte encoding
    std::wstring wstr = L"z\u00df\u6c34\U0001d10b"; // or L"zß水𝄋"
    print_wide(wstr);
}

