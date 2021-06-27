/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_time_put_byname.exe ./cpp/locale_time_put_byname.cpp && (cd ../_build/cpp/;./locale_time_put_byname.exe) || true
https://en.cppreference.com/w/cpp/locale/time_put_byname
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
    out.imbue(std::locale(out.getloc(),
                          new std::time_put_byname<wchar_t>("ja_JP")));
    out << std::put_time(std::localtime(&t), L"%A %c") << '\n';
    out.imbue(std::locale(out.getloc(),
                         new std::time_put_byname<wchar_t>("ru_RU.utf8")));
    out << std::put_time(std::localtime(&t), L"%A %c") << '\n'; 
    out.imbue(std::locale(out.getloc(),
                         new std::time_put_byname<wchar_t>("sv_SE.utf8")));
    out << std::put_time(std::localtime(&t), L"%A %c") << '\n'; 
}

