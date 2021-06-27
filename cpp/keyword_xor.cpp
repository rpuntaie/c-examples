/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_xor.exe ./cpp/keyword_xor.cpp && (cd ../_build/cpp/;./keyword_xor.exe)
https://en.cppreference.com/w/cpp/keyword/xor
*/
#include <iostream>
#include <bitset>
using bin = std::bitset<8>;
void show(bin z, const char* s, int n)
{
    if (n == 0) std::cout << "┌─────────┬──────────┐\n";
    if (n <= 2) std::cout << "│ "<<s<<" │ " <<z<<" │\n";
    if (n == 2) std::cout << "└─────────┴──────────┘\n";
}
int main()
{
    bin x{ "01011010" }; show(x, "x      ", 0);
    bin y{ "00111100" }; show(y, "y      ", 1);
    bin z = x xor y;     show(z, "x xor y", 2);
}

