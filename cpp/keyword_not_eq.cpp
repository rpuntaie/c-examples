/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_not_eq.exe ./cpp/keyword_not_eq.cpp && (cd ../_build/cpp/;./keyword_not_eq.exe)
https://en.cppreference.com/w/cpp/keyword/not_eq
*/
#include <iostream>
void show(bool z, const char* s, int n)
{
    const char* r { z ? " true  " : " false " };
    if (n == 0) std::cout << "┌────────────────────┬─────────┐\n";
    if (n <= 2) std::cout << "│ "      <<s<<     " │ "<<r<<" │\n";
    if (n == 2) std::cout << "└────────────────────┴─────────┘\n";
}
int main()
{
    show(false not_eq false, "false not_eq false", 0);
    show(false not_eq true , "false not_eq true ", 1);
    show(true  not_eq false, "true  not_eq false", 1);
    show(true  not_eq true , "true  not_eq true ", 2);
}

