/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_localtime.exe ./cpp/chrono_c_localtime.cpp && (cd ../_build/cpp/;./chrono_c_localtime.exe)
https://en.cppreference.com/w/cpp/chrono/c/localtime
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
int main()
{
    setenv("TZ", "/usr/share/zoneinfo/America/Los_Angeles", 1); // POSIX-specific
    std::tm tm{};  // zero initialise
    tm.tm_year = 2020-1900; // 2020
    tm.tm_mon = 2-1; // February
    tm.tm_mday = 15; // 15th
    tm.tm_hour = 10;
    tm.tm_min = 15;
    tm.tm_isdst = 0; // Not daylight saving
    std::time_t t = std::mktime(&tm); 
    std::cout << "UTC:   " << std::put_time(std::gmtime(&t), "%c %Z") << '\n';
    std::cout << "local: " << std::put_time(std::localtime(&t), "%c %Z") << '\n';
}

