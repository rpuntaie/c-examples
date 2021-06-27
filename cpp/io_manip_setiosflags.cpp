/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_setiosflags.exe ./cpp/io_manip_setiosflags.cpp && (cd ../_build/cpp/;./io_manip_setiosflags.exe)
https://en.cppreference.com/w/cpp/io/manip/setiosflags
*/
#include <iostream>
#include <iomanip>
int main()
{
    std::cout <<  std::resetiosflags(std::ios_base::dec) 
              <<  std::setiosflags(  std::ios_base::hex
                                   | std::ios_base::uppercase
                                   | std::ios_base::showbase) << 42 << '\n';
}

