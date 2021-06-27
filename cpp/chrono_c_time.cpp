/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_time.exe ./cpp/chrono_c_time.cpp && (cd ../_build/cpp/;./chrono_c_time.exe)
https://en.cppreference.com/w/cpp/chrono/c/time
*/
#include <ctime>
#include <iostream>
int main()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
}

