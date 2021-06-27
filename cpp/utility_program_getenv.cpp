/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_getenv.exe ./cpp/utility_program_getenv.cpp && (cd ../_build/cpp/;./utility_program_getenv.exe)
https://en.cppreference.com/w/cpp/utility/program/getenv
*/
#include <iostream>
#include <cstdlib>
int main()
{
    if(const char* env_p = std::getenv("PATH"))
        std::cout << "Your PATH is: " << env_p << '\n';
}

