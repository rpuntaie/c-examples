/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_exception_ptr.exe ./cpp/error_exception_ptr.cpp && (cd ../_build/cpp/;./error_exception_ptr.exe)
https://en.cppreference.com/w/cpp/error/exception_ptr
*/
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}
int main()
{
    std::exception_ptr eptr;
    try {
        std::string().at(1); // this generates an std::out_of_range
    } catch(...) {
        eptr = std::current_exception(); // capture
    }
    handle_eptr(eptr);
} // destructor for std::out_of_range called here, when the eptr is destructed

