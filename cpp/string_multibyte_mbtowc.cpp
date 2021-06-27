/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_mbtowc.exe ./cpp/string_multibyte_mbtowc.cpp && (cd ../_build/cpp/;./string_multibyte_mbtowc.exe)
https://en.cppreference.com/w/cpp/string/multibyte/mbtowc
*/
#include <iostream>
#include <clocale>
#include <cstring>
#include <cstdlib>
int print_mb(const char* ptr)
{
    std::mbtowc(nullptr, 0, 0); // reset the conversion state
    const char* end = ptr + std::strlen(ptr);
    int ret;
    for (wchar_t wc; (ret = std::mbtowc(&wc, ptr, end-ptr)) > 0; ptr+=ret) {
        std::wcout << wc;
    }
    std::wcout << '\n';
    return ret;
}
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    // UTF-8 narrow multibyte encoding
    const char* str = "z\u00df\u6c34\U0001d10b"; // or u8"zß水𝄋"
                      // or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
    print_mb(str);
}

