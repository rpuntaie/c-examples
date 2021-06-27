/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_iostream_category.exe ./cpp/io_iostream_category.cpp && (cd ../_build/cpp/;./io_iostream_category.exe)
https://en.cppreference.com/w/cpp/io/iostream_category
*/
#include <iostream>
#include <fstream>
int main()
{
    std::ifstream f("doesn't exist");
    try {
        f.exceptions(f.failbit);
    } catch (const std::ios_base::failure& e) {
        std::cout << "Caught an ios_base::failure.\n"
                  << "Error code: " << e.code().value() 
                  << " (" << e.code().message() << ")\n"
                  << "Error category: " << e.code().category().name() << '\n';
    }
}

