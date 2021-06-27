/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcstoimax.exe ./cpp/string_wide_wcstoimax.cpp && (cd ../_build/cpp/;./string_wide_wcstoimax.exe)
https://en.cppreference.com/w/cpp/string/wide/wcstoimax
*/
#include <iostream>
#include <string>
#include <cinttypes>
int main()
{
    std::wstring str = L"helloworld";
    std::intmax_t val = std::wcstoimax(str.c_str(), nullptr, 36);
    std::wcout << str << " in base 36 is " << val << " in base 10\n";
    wchar_t* nptr;
    val = std::wcstoimax(str.c_str(), &nptr, 30);
    if(nptr != &str[0] + str.size())
        std::wcout << str << " in base 30 is invalid."
                  << " The first invalid digit is " << *nptr << '\n';
}

