/*
g++ --std=c++20 -pthread -o ../_build/cpp/concepts_signed_integral.exe ./cpp/concepts_signed_integral.cpp && (cd ../_build/cpp/;./concepts_signed_integral.exe)
https://en.cppreference.com/w/cpp/concepts/signed_integral
*/
#include <concepts>
#include <iostream>
void print(std::signed_integral auto i) {
    std::cout << "Signed integral: " << i << '\n';
}
void print(std::unsigned_integral auto u) {
    std::cout << "Unsigned integral: " << u << '\n';
}
void print(auto x) {
    std::cout << "Non-integral: " << x << '\n';
}
int main() {
    print(42);     // signed
    print(0xFull); // unsigned
    print(true);   // unsigned
    print('A');    // platform-dependent
    print(4e-2);   // non-integral (hex-float)
    print("∫∫∫");  // non-integral
}

