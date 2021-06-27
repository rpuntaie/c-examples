/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_locale.exe ./cpp/locale_locale.cpp && (cd ../_build/cpp/;./locale_locale.exe)
https://en.cppreference.com/w/cpp/locale/locale
*/
#include <iostream>
#include <locale>
int main()
{
    std::wcout << "User-preferred locale setting is " << std::locale("").name().c_str() << '\n';
    // on startup, the global locale is the "C" locale
    std::wcout << 1000.01 << '\n';
    // replace the C++ global locale as well as the C locale with the user-preferred locale
    std::locale::global(std::locale(""));
    // use the new global locale for future wide character output
    std::wcout.imbue(std::locale());
    // output the same number again
    std::wcout << 1000.01 << '\n';
}

