/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_tm.exe ./cpp/chrono_c_tm.cpp && (cd ../_build/cpp/;./chrono_c_tm.exe)
https://en.cppreference.com/w/cpp/chrono/c/tm
*/
#include <ctime>
#include <iostream>
int main()
{
    std::tm start{};
    start.tm_mday = 1;
    std::mktime(&start);
    std::cout << std::asctime(&start)
              << "sizeof(std::tm) = "
              << sizeof(std::tm) << '\n';
}

