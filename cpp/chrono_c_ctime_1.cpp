/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_ctime_1.exe ./cpp/chrono_c_ctime_1.cpp && (cd ../_build/cpp/;./chrono_c_ctime_1.exe)
https://en.cppreference.com/w/cpp/chrono/c/ctime
*/
#include <ctime>
#include <iostream>
int main()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::ctime(&result);
}

