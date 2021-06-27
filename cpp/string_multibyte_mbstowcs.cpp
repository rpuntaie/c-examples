/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_mbstowcs.exe ./cpp/string_multibyte_mbstowcs.cpp && (cd ../_build/cpp/;./string_multibyte_mbstowcs.exe)
https://en.cppreference.com/w/cpp/string/multibyte/mbstowcs
*/
#include <iostream>
#include <clocale>
#include <cstdlib>
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    const char* mbstr = "z\u00df\u6c34\U0001f34c"; // or u8"zß水🍌"
                        // or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
    wchar_t wstr[5];
    std::mbstowcs(wstr, mbstr, 5);
    std::wcout << "wide string: " << wstr << '\n';
}

