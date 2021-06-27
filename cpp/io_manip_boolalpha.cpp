/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_boolalpha.exe ./cpp/io_manip_boolalpha.cpp && (cd ../_build/cpp/;./io_manip_boolalpha.exe)
https://en.cppreference.com/w/cpp/io/manip/boolalpha
*/
#include <sstream>
#include <locale>
#include <iostream>
int main()
{
    // boolalpha output
    std::cout << std::boolalpha 
              << "boolalpha true: " << true << '\n'
              << "boolalpha false: " << false << '\n';
    std::cout << std::noboolalpha 
              << "noboolalpha true: " << true << '\n'
              << "noboolalpha false: " << false << '\n';
    // boolalpha parse
    bool b1, b2;
    std::istringstream is("true false");
    is >> std::boolalpha >> b1 >> b2;
    std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';
}

