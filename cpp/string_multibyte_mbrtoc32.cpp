/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_multibyte_mbrtoc32.exe ./cpp/string_multibyte_mbrtoc32.cpp && (cd ../_build/cpp/;./string_multibyte_mbrtoc32.exe)
https://en.cppreference.com/w/cpp/string/multibyte/mbrtoc32
*/
#include <iostream>
#include <iomanip>
#include <clocale>
#include <cstring>
#include <cwchar>
#include <cuchar>
#include <cassert>
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    std::string str = "z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"
    std::cout << "Processing " << str.size() << " bytes: [ " << std::showbase;
    for(unsigned char c: str) std::cout << std::hex << +c << ' ';
    std::cout << "]\n";
    std::mbstate_t state{}; // zero-initialized to initial state
    char32_t c32;
    const char *ptr = str.c_str(), *end = str.c_str() + str.size() + 1;
    while(std::size_t rc = std::mbrtoc32(&c32, ptr, end - ptr, &state))
    {   
        std::cout << "Next UTF-32 char: " << std::hex
                  << static_cast<int>(c32) << " obtained from ";
        assert(rc != (std::size_t)-3); // no surrogates in UTF-32
        if(rc == (std::size_t)-1) break;
        if(rc == (std::size_t)-2) break;
        std::cout << std::dec << rc << " bytes [ ";
        for(std::size_t n = 0; n < rc; ++n)
            std::cout << std::hex << +static_cast<unsigned char>(ptr[n]) << ' ';
        std::cout << "]\n";
        ptr += rc;
    }
}

