/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_endian_1.exe ./cpp/types_endian_1.cpp && (cd ../_build/cpp/;./types_endian_1.exe)
https://en.cppreference.com/w/cpp/types/endian
*/
#include <bit>
#include <iostream>
int main() {
    if constexpr (std::endian::native == std::endian::big) {
        std::cout << "big-endian" << '\n';
    }
    else if constexpr (std::endian::native == std::endian::little) {
        std::cout << "little-endian"  << '\n';
    }
    else {
        std::cout << "mixed-endian"  << '\n';
    }
}

