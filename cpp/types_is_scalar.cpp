/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_scalar.exe ./cpp/types_is_scalar.cpp && (cd ../_build/cpp/;./types_is_scalar.exe)
https://en.cppreference.com/w/cpp/types/is_scalar
*/
#include <iostream>
#include <type_traits>
int main() {
    class cls {};
    std::cout << (std::is_scalar<int>::value
                     ? "T is a scalar"
                     : "T is not a scalar") << '\n';
    std::cout << (std::is_scalar<cls>::value
                     ? "T is a scalar"
                     : "T is not a scalar") << '\n';
}

