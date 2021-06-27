/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_or.exe ./cpp/keyword_or.cpp && (cd ../_build/cpp/;./keyword_or.exe)
https://en.cppreference.com/w/cpp/keyword/or
*/
#include <iostream>
void show(bool z, const char* s, int n)
{
    const char* r{z ? " true  " : " false "};
    if (n == 0) std::cout << "┌────────────────┬─────────┐\n";
    if (n <= 2) std::cout << "│ "   <<s<<    " │ "<<r<<" │\n";
    if (n == 2) std::cout << "└────────────────┴─────────┘\n";
}
int main()
{
    show(false or false, "false or false", 0);
    show(false or true , "false or true ", 1);
    show(true  or false, "true  or false", 1);
    show(true  or true , "true  or true ", 2);
}

