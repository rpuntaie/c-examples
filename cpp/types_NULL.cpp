/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_NULL.exe ./cpp/types_NULL.cpp && (cd ../_build/cpp/;./types_NULL.exe)
https://en.cppreference.com/w/cpp/types/NULL
*/
#include <cstddef>
#include <type_traits>
#include <iostream>
class S;
int main()
{
    int* p = NULL;
    int* p2 = static_cast<std::nullptr_t>(NULL);
    void(*f)(int) = NULL;
    int S::*mp = NULL;
    void(S::*mfp)(int) = NULL;
    if constexpr(std::is_same_v<decltype(NULL), std::nullptr_t>) {
        std::cout << "NULL implemented with type std::nullptr_t\n";
    } else {
        std::cout << "NULL implemented using an integral type\n";
    }
    [](auto...){}(p, p2, f, mp, mfp); //< garbage "unused" variables
}

