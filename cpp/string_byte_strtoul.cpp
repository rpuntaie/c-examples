/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strtoul.exe ./cpp/string_byte_strtoul.cpp && (cd ../_build/cpp/;./string_byte_strtoul.exe)
https://en.cppreference.com/w/cpp/string/byte/strtoul
*/
#include <iostream>
#include <string>
#include <errno.h>
#include <cstdlib>
int main()
{
    const char* p = "10 200000000000000000000000000000 30 -40";
    char *end;
    std::cout << "Parsing '" << p << "':\n";
    for (unsigned long i = std::strtoul(p, &end, 10);
         p != end;
         i = std::strtoul(p, &end, 10))
    {
        std::cout << "'" << std::string(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::cout << "range error, got ";
            errno = 0;
        }
        std::cout << i << '\n';
    }
}

