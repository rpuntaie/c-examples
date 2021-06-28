/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_9.exe ./cpp/language_pointer_9.cpp && (cd ../_build/cpp/;./language_pointer_9.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
#include <iostream>
int f(int n)
{
    std::cout << n << '\n';
    return n * n;
}
int main()
{
    int (*p)(int) = f;
    int x = p(7);
}

