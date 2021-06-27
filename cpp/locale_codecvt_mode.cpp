/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_codecvt_mode.exe ./cpp/locale_codecvt_mode.cpp && (cd ../_build/cpp/;./locale_codecvt_mode.exe)
https://en.cppreference.com/w/cpp/locale/codecvt_mode
*/
#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
int main()
{
    // UTF-8 data with BOM
    std::ofstream("text.txt") << u8"\ufeffz\u6c34\U0001d10b";
    // read the UTF8 file, skipping the BOM
    std::wifstream fin("text.txt");
    fin.imbue(std::locale(fin.getloc(),
                          new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
    for (wchar_t c; fin.get(c); )
        std::cout << std::hex << std::showbase << c << '\n';
}

