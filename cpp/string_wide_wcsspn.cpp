/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcsspn.exe ./cpp/string_wide_wcsspn.cpp && (cd ../_build/cpp/;./string_wide_wcsspn.exe)
https://en.cppreference.com/w/cpp/string/wide/wcsspn
*/
#include <cwchar>
#include <iostream>
#include <locale>
int main()
{
    wchar_t dest[] = L"白猫 黑狗 甲虫";
    const wchar_t src[] = L" 狗猫 白黑 ";
    const std::size_t len = std::wcsspn(dest, src);
    dest[len] = L'\0'; // terminates the segment to print it out
    std::wcout.imbue(std::locale("en_US.utf8"));
    std::wcout << L"The length of maximum initial segment is " << len << L".\n";
    std::wcout << L"The segment is \"" << dest << L"\".\n";
}

