/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_ws.exe ./cpp/io_manip_ws.cpp && (cd ../_build/cpp/;./io_manip_ws.exe)
https://en.cppreference.com/w/cpp/io/manip/ws
*/
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
int main()
{
    std::istringstream s("     this is a test");
    std::string line;
    std::getline(s >> std::ws, line);
    std::cout << "ws + getline returns: \"" << line << "\"\n";
}

