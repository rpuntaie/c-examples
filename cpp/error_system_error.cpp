/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_system_error.exe ./cpp/error_system_error.cpp && (cd ../_build/cpp/;./error_system_error.exe)
https://en.cppreference.com/w/cpp/error/system_error
*/
#include <thread>
#include <iostream>
#include <system_error>
int main()
{
    try {
        std::thread().detach(); // attempt to detach a non-thread
    } catch(const std::system_error& e) {
        std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << '\n';
    }
}

