/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_atexit.exe ./cpp/utility_program_atexit.cpp && (cd ../_build/cpp/;./utility_program_atexit.exe) || true
https://en.cppreference.com/w/cpp/utility/program/atexit
*/
#include <iostream>
#include <cstdlib>
void atexit_handler_1() 
{
    std::cout << "at exit #1\n";
}
void atexit_handler_2() 
{
    std::cout << "at exit #2\n";
}
int main() 
{
    const int result_1 = std::atexit(atexit_handler_1);
    const int result_2 = std::atexit(atexit_handler_2);
    if ((result_1 != 0) || (result_2 != 0)) {
        std::cerr << "Registration failed\n";
        return EXIT_FAILURE;
    }
    std::cout << "returning from main\n";
    return EXIT_SUCCESS;
}

