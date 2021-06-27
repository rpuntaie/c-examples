/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strncmp.exe ./cpp/string_byte_strncmp.cpp && (cd ../_build/cpp/;./string_byte_strncmp.exe)
https://en.cppreference.com/w/cpp/string/byte/strncmp
*/
#include <cstring>
#include <iostream>
void demo(const char* lhs, const char* rhs, int sz)
{
    int rc = std::strncmp(lhs, rhs, sz);
    if(rc == 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] equal [" << rhs << "]\n";
    else if(rc < 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] precede [" << rhs << "]\n";
    else if(rc > 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] follow [" << rhs << "]\n";
}
int main()
{
    demo("Hello, world!", "Hello, everybody!", 13);
    demo("Hello, everybody!", "Hello, world!", 13);
    demo("Hello, everybody!", "Hello, world!", 7);
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);
}

