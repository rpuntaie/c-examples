/*
g++ -std=c++20 -o ../_build/r/go.exe r/go1.cpp r/go.cpp && (cd ../_build/r;./go.exe)
*/

#include <iostream>

extern constinit int staticA;
auto staticB = staticA;

int main() {
std::cout << '\n';
std::cout << "staticB: " << staticB << '\n';
std::cout << '\n';
}
