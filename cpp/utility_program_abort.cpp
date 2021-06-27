/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_abort.exe ./cpp/utility_program_abort.cpp && (cd ../_build/cpp/;./utility_program_abort.exe) || true
https://en.cppreference.com/w/cpp/utility/program/abort
*/
#include <csignal>
#include <iostream>
#include <cstdlib>
class Tester {
public:
    Tester()  { std::cout << "Tester ctor\n"; }
    ~Tester() { std::cout << "Tester dtor\n"; }
};
Tester static_tester; // Destructor not called
void signal_handler(int signal) 
{
    if (signal == SIGABRT) {
        std::cerr << "SIGABRT received\n";
    } else {
        std::cerr << "Unexpected signal " << signal << " received\n";
    }
    std::_Exit(EXIT_FAILURE);
}
int main()
{
    Tester automatic_tester; // Destructor not called
    // Setup handler
    auto previous_handler = std::signal(SIGABRT, signal_handler);
    if (previous_handler == SIG_ERR) {
        std::cerr << "Setup failed\n";
        return EXIT_FAILURE;
    }
    std::abort();  // Raise SIGABRT
    std::cout << "This code is unreachable\n";
}

