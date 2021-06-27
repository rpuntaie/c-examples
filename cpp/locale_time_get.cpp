/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_time_get.exe ./cpp/locale_time_get.cpp && (cd ../_build/cpp/;./locale_time_get.exe)
https://en.cppreference.com/w/cpp/locale/time_get
*/
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
int main()
{
    std::tm t = {};
    std::istringstream ss("2011-Februar-18 23:12:34");
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
    if (ss.fail()) {
        std::cout << "Parse failed\n";
    } else {
        std::cout << std::put_time(&t, "%c") << '\n';
    }
}

