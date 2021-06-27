/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_ends.exe ./cpp/io_manip_ends.cpp && (cd ../_build/cpp/;./io_manip_ends.exe)
https://en.cppreference.com/w/cpp/io/manip/ends
*/
#include <cstdio>
#include <strstream>
int main()
{
    std::ostrstream oss;
    oss << "Sample text: " << 42 << std::ends;
    std::printf("%s\n", oss.str());
    oss.freeze(false); // enable memory deallocation
}

