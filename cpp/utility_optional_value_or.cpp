/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_value_or.exe ./cpp/utility_optional_value_or.cpp && (cd ../_build/cpp/;./utility_optional_value_or.exe)
https://en.cppreference.com/w/cpp/utility/optional/value_or
*/
#include <optional>
#include <iostream>
#include <cstdlib>
std::optional<const char*> maybe_getenv(const char* n)
{
    if(const char* x = std::getenv(n))
       return x;
    else
       return {};
}
int main()
{
     std::cout << maybe_getenv("MYPWD").value_or("(none)") << '\n';
}

