/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_exit.exe ./cpp/utility_program_exit.cpp && (cd ../_build/cpp/;./utility_program_exit.exe) || true
https://en.cppreference.com/w/cpp/utility/program/exit
*/
#include <iostream>
#include <cstdlib>
struct Static {
    ~Static() 
    {
        std::cout << "Static dtor\n";
    }
};
struct Local {
    ~Local() 
    {
        std::cout << "Local dtor\n";
    }
};
Static static_variable; // dtor of this object *will* be called
void atexit_handler()
{
    std::cout << "atexit handler\n";
}
int main()
{
    Local local_variable; // dtor of this object will *not* be called
    const int result = std::atexit(atexit_handler); // handler will be called
    if (result != 0) {
        std::cerr << "atexit registration failed\n";
        return EXIT_FAILURE;
    }
    std::cout << "test\n";
    std::exit(EXIT_FAILURE);
    std::cout << "this line will *not* be executed\n";
}

