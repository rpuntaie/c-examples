/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_compl.exe ./cpp/keyword_compl.cpp && (cd ../_build/cpp/;./keyword_compl.exe)
https://en.cppreference.com/w/cpp/keyword/compl
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
    bin z = compl x;     show(z, "compl x", 2);
}

