/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcstok.exe ./cpp/string_wide_wcstok.cpp && (cd ../_build/cpp/;./string_wide_wcstok.exe)
https://en.cppreference.com/w/cpp/string/wide/wcstok
*/
#include <cwchar>
#include <iostream>
int main()
{
    wchar_t input[100] = L"A bird came down the walk";
    wchar_t* buffer;
    wchar_t* token = std::wcstok(input, L" ", &buffer);
    while (token) {
        std::wcout << token << '\n';
        token = std::wcstok(nullptr, L" ", &buffer);
    }
}

