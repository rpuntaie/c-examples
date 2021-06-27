/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_ctype.exe ./cpp/locale_ctype.cpp && (cd ../_build/cpp/;./locale_ctype.exe)
https://en.cppreference.com/w/cpp/locale/ctype
*/
#include <iostream>
#include <locale>
#include <sstream>
struct csv_whitespace : std::ctype<wchar_t>
{
    bool do_is(mask m, char_type c) const
    {   
        if ((m & space) && c == L' ') {
            return false; // space will NOT be classified as whitespace
        }
        if ((m & space) && c == L',') {
            return true; // comma will be classified as whitespace
        }
        return ctype::do_is(m, c); // leave the rest to the parent class
    } 
};
int main()
{
    std::wstring in = L"Column 1,Column 2,Column 3\n123,456,789";
    std::wstring token;
    std::wcout << "default locale:\n";
    std::wistringstream s1(in);
    while (s1 >> token) {
        std::wcout << "  " << token << '\n';
    }
    std::wcout << "locale with modified ctype:\n";
    std::wistringstream s2(in);
    csv_whitespace* my_ws = new csv_whitespace;
    s2.imbue(std::locale(s2.getloc(), my_ws));
    while (s2 >> token) {
        std::wcout << "  " << token<< '\n';
    }
}

