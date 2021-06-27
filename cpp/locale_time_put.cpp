/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_time_put.exe ./cpp/locale_time_put.cpp && (cd ../_build/cpp/;./locale_time_put.exe) || true
https://en.cppreference.com/w/cpp/locale/time_put
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <codecvt>
int main()
{
    std::time_t t = std::time(nullptr);
    std::wbuffer_convert<std::codecvt_utf8<wchar_t>> conv(std::cout.rdbuf());
    std::wostream out(&conv);
    out.imbue(std::locale("ja_JP.utf8"));
    // this I/O manipulator std::put_time uses std::time_put<wchar_t>
    out << std::put_time(std::localtime(&t), L"%A %c") << '\n';
}

