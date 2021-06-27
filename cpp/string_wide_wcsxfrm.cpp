/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcsxfrm.exe ./cpp/string_wide_wcsxfrm.cpp && (cd ../_build/cpp/;./string_wide_wcsxfrm.exe)
https://en.cppreference.com/w/cpp/string/wide/wcsxfrm
*/
#include <iostream>
#include <cwchar>
int main()
{
    std::setlocale(LC_ALL, "sv_SE.utf8");
    std::wstring in1 = L"\u00e5r";
    std::wstring out1(1+std::wcsxfrm(nullptr, in1.c_str(), 0), L' ');
    std::wstring in2 = L"\u00e4ngel";
    std::wstring out2(1+std::wcsxfrm(nullptr, in2.c_str(), 0), L' ');
    std::wcsxfrm(&out1[0], in1.c_str(), out1.size());
    std::wcsxfrm(&out2[0], in2.c_str(), out2.size());
    std::wcout << "In the Swedish locale: ";
    if(out1 < out2)
         std::wcout << in1 << " before " << in2 << '\n';
    else
         std::wcout << in2 << " before " << in1 << '\n';
    std::wcout << "In lexicographical comparison: ";
    if(in1 < in2)
         std::wcout << in1 << " before " << in2 << '\n';
    else
         std::wcout << in2 << " before " << in1 << '\n';
}

