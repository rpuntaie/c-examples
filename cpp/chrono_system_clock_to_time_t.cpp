/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_system_clock_to_time_t.exe ./cpp/chrono_system_clock_to_time_t.cpp && (cd ../_build/cpp/;./chrono_system_clock_to_time_t.exe)
https://en.cppreference.com/w/cpp/chrono/system_clock/to_time_t
*/
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;
int main()
{
    // The old way
    std::time_t oldt = std::time(nullptr);
    std::this_thread::sleep_for(2700ms);
    // The new way
    std::time_t newt = std::chrono::system_clock::to_time_t(
                           std::chrono::system_clock::now());
    std::cout << "oldt-newt == " << oldt-newt << " s\n";
}

