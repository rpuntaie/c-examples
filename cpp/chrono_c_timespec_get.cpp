/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_timespec_get.exe ./cpp/chrono_c_timespec_get.cpp && (cd ../_build/cpp/;./chrono_c_timespec_get.exe)
https://en.cppreference.com/w/cpp/chrono/c/timespec_get
*/
#include <cstdio>
#include <ctime>
int main()
{
    std::timespec ts;
    std::timespec_get(&ts, TIME_UTC);
    char buf[100];
    std::strftime(buf, sizeof buf, "%D %T", std::gmtime(&ts.tv_sec));
    std::printf("Current time: %s.%09ld UTC\n", buf, ts.tv_nsec);
}

