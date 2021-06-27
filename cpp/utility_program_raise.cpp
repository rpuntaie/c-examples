/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_raise.exe ./cpp/utility_program_raise.cpp && (cd ../_build/cpp/;./utility_program_raise.exe)
https://en.cppreference.com/w/cpp/utility/program/raise
*/
#include <csignal>
#include <iostream>
void signal_handler(int signal)
{
    std::cout << "Received signal " << signal << '\n';
}
int main()
{
    // Install a signal handler
    std::signal(SIGTERM, signal_handler);
    std::cout << "Sending signal " << SIGTERM << '\n';
    std::raise(SIGTERM);
}

