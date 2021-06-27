/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_codecvt_utf8_utf16.exe ./cpp/locale_codecvt_utf8_utf16.cpp && (cd ../_build/cpp/;./locale_codecvt_utf8_utf16.exe)
https://en.cppreference.com/w/cpp/locale/codecvt_utf8_utf16
*/
#include <iostream>
#include <string>
#include <codecvt>
#include <cassert>
#include <locale>
int main()
{
    std::string u8 = u8"z\u00df\u6c34\U0001f34c";
    std::u16string u16 = u"z\u00df\u6c34\U0001f34c";
    // UTF-8 to UTF-16/char16_t
    std::u16string u16_conv = std::wstring_convert<
        std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(u8);
    assert(u16 == u16_conv);
    std::cout << "UTF-8 to UTF-16 conversion produced "
              << u16_conv.size() << " code units:\n";
    for (char16_t c : u16_conv)
        std::cout << std::hex << std::showbase << c << ' ';
    // UTF-16/char16_t to UTF-8
    std::string u8_conv = std::wstring_convert<
        std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16);
    assert(u8 == u8_conv);
    std::cout << "\nUTF-16 to UTF-8 conversion produced "
              << std::dec << u8_conv.size() << " bytes:\n" << std::hex;
    for (char c : u8_conv)
        std::cout << +(unsigned char)c << ' ';
}

