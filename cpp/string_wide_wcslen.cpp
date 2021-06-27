/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcslen.exe ./cpp/string_wide_wcslen.cpp && (cd ../_build/cpp/;./string_wide_wcslen.exe)
https://en.cppreference.com/w/cpp/string/wide/wcslen
*/
#include <iostream>
#include <cwchar>
#include <clocale>
int main()
{
    const wchar_t* str = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    std::wcout << "The length of \"" << str << "\" is " << std::wcslen(str) << '\n';
}

