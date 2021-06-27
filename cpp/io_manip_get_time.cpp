/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_get_time.exe ./cpp/io_manip_get_time.cpp && (cd ../_build/cpp/;./io_manip_get_time.exe)
https://en.cppreference.com/w/cpp/io/manip/get_time
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

