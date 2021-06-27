/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_wcrtomb.exe ./cpp/string_multibyte_wcrtomb.cpp && (cd ../_build/cpp/;./string_multibyte_wcrtomb.exe)
https://en.cppreference.com/w/cpp/string/multibyte/wcrtomb
*/
#include <iostream>
#include <clocale>
#include <string>
#include <cwchar>
void print_wide(const std::wstring& wstr)
{
    std::mbstate_t state {};
    for(wchar_t wc : wstr) {
        std::string mb(MB_CUR_MAX, '\0');
        std::size_t ret = std::wcrtomb(&mb[0], wc, &state);
        std::cout << "multibyte char " << mb << " is " << ret << " bytes\n";
    }
}
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wstring wstr = L"z\u00df\u6c34\U0001f34c"; // or L"zß水🍌"
    print_wide(wstr);
}

