/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_difftime.exe ./cpp/chrono_c_difftime.cpp && (cd ../_build/cpp/;./chrono_c_difftime.exe)
https://en.cppreference.com/w/cpp/chrono/c/difftime
*/
#include <iostream>
#include <ctime>
int main()
{
    std::time_t start = std::time(nullptr);
    volatile double d = 1.0;
    // some time-consuming operation
    for (int p=0; p<10000; ++p) {
        for (int q=0; q<100000; ++q) {
           d = d+p*d*q+d;
        }
    }
    std::cout << "Wall time passed: "
              << std::difftime(std::time(nullptr), start) << " s.\n";
}

