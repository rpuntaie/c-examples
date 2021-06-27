/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_c_strftime.exe ./cpp/chrono_c_strftime.cpp && (cd ../_build/cpp/;./chrono_c_strftime.exe) || true
https://en.cppreference.com/w/cpp/chrono/c/strftime
*/
#include <ctime>
#include <iostream>
#include <locale>
int main()
{
    std::locale::global(std::locale("ja_JP.utf8"));
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t))) {
        std::cout << mbstr << '\n';
    }
}

