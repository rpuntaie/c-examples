/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_to_wstring.exe ./cpp/string_basic_string_to_wstring.cpp && (cd ../_build/cpp/;./string_basic_string_to_wstring.exe)
https://en.cppreference.com/w/cpp/string/basic_string/to_wstring
*/
#include <string>
#include <iostream>
int main() {
    double f = 23.43;  
    std::wstring f_str = std::to_wstring(f);
    std::wcout << f_str;
}

