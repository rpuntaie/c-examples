/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_throw_1.exe ./cpp/language_throw_1.cpp && (cd ../_build/cpp/;./language_throw_1.exe)
https://en.cppreference.com/w/cpp/language/throw
*/
#include <iostream>
double f(double d)
{
    return d > 1e7 ? throw std::overflow_error("too big") : d;
}
int main()  
{
    try {
        std::cout << f(1e10) << '\n';
    } catch (const std::overflow_error& e) {
        std::cout << e.what() << '\n';
    }
}

