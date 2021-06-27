/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_compound.exe ./cpp/types_is_compound.cpp && (cd ../_build/cpp/;./types_is_compound.exe)
https://en.cppreference.com/w/cpp/types/is_compound
*/
#include <iostream>
#include <type_traits>
int main() {
    class cls {};
    std::cout << (std::is_compound<cls>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';
    std::cout << (std::is_compound<int>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';
}

