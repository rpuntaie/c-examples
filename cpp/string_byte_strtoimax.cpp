/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strtoimax.exe ./cpp/string_byte_strtoimax.cpp && (cd ../_build/cpp/;./string_byte_strtoimax.exe)
https://en.cppreference.com/w/cpp/string/byte/strtoimax
*/
#include <iostream>
#include <string>
#include <cinttypes>
int main()
{
    std::string str = "helloworld";
    std::intmax_t val = std::strtoimax(str.c_str(), nullptr, 36);
    std::cout << str << " in base 36 is " << val << " in base 10\n";
    char* nptr;
    val = std::strtoimax(str.c_str(), &nptr, 30);
    if(nptr != &str[0] + str.size())
        std::cout << str << " in base 30 is invalid."
                  << " The first invalid digit is '" << *nptr << "'\n";
}

