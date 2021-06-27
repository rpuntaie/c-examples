/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_not.exe ./cpp/keyword_not.cpp && (cd ../_build/cpp/;./keyword_not.exe)
https://en.cppreference.com/w/cpp/keyword/not
*/
#include <iostream>
void show(bool z, const char* s, int n)
{
    const char* r{z ? " true  " : " false "};
    if (n == 0) std::cout << "┌───────────┬─────────┐\n";
    if (n <= 1) std::cout << "│ " <<s<< " │ "<<r<<" │\n";
    if (n == 1) std::cout << "└───────────┴─────────┘\n";
}
int main()
{
    show(not true , "not true ", 0);
    show(not false, "not false", 1);
}

