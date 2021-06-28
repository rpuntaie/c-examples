/*
NOT c++17...
g++ --std=c++11 -pthread -o ../_build/cpp/error_bad_exception.exe ./cpp/error_bad_exception.cpp && (cd ../_build/cpp/;./error_bad_exception.exe)
https://en.cppreference.com/w/cpp/error/bad_exception
*/
#include <iostream>
#include <exception>
#include <stdexcept>
void my_unexp() { throw; }
void test() throw(std::bad_exception)
{
    throw std::runtime_error("test");
}
int main()
{
    std::set_unexpected(my_unexp);
    try {
         test();
    } catch(const std::bad_exception& e)
    {
        std::cerr << "Caught " << e.what() << '\n';
    }
}

