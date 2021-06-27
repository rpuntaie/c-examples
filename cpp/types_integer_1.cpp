/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_integer_1.exe ./cpp/types_integer_1.cpp && (cd ../_build/cpp/;./types_integer_1.exe)
https://en.cppreference.com/w/cpp/types/integer
*/
#include <cstdio>
#include <cinttypes>
int main()
{
    std::printf("%zu\n", sizeof(std::int64_t));
    std::printf("%s\n", PRId64);
    std::printf("%+" PRId64 "\n", INT64_MIN);
    std::printf("%+" PRId64 "\n", INT64_MAX);
    std::int64_t n = 7;
    std::printf("%+" PRId64 "\n", n);
}

