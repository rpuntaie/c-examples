/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_set_terminate.exe ./cpp/error_set_terminate.cpp && (cd ../_build/cpp/;./error_set_terminate.exe) || true
https://en.cppreference.com/w/cpp/error/set_terminate
*/
#include <iostream>
#include <cstdlib>
#include <exception>
int main()
{
    std::set_terminate([](){ std::cout << "Unhandled exception" << std::endl; std::abort();});
    throw 1;
}

