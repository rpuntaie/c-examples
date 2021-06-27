/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_memcmp.exe ./cpp/string_byte_memcmp.cpp && (cd ../_build/cpp/;./string_byte_memcmp.exe)
https://en.cppreference.com/w/cpp/string/byte/memcmp
*/
#include <iostream>
#include <cstring>
void demo(const char* lhs, const char* rhs, std::size_t sz)
{
    std::cout << std::string(lhs, sz);
    int rc = std::memcmp(lhs, rhs, sz);
    if(rc == 0)
        std::cout << " compares equal to ";
    else if(rc < 0)
        std::cout << " precedes ";
    else if(rc > 0)
        std::cout << " follows ";
    std::cout << std::string(rhs, sz) << " in lexicographical order\n";
}
int main()
{
    char a1[] = {'a','b','c'};
    char a2[sizeof a1] = {'a','b','d'};
    demo(a1, a2, sizeof a1);
    demo(a2, a1, sizeof a1);
    demo(a1, a1, sizeof a1);
}

