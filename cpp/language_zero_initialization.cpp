/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_zero_initialization.exe ./cpp/language_zero_initialization.cpp && (cd ../_build/cpp/;./language_zero_initialization.exe)
https://en.cppreference.com/w/cpp/language/zero_initialization
*/
#include <string>
#include <iostream>
struct A {
    int a,b,c;
};
double f[3]; // zero-initialized to three 0.0's
int* p; // zero-initialized to null pointer value (even if the value is not integral 0)
std::string s; // zero-initialized to indeterminate value
               // then default-initialized to "" by the std::string default constructor
int main(int argc, char*[])
{
    delete p; // safe to delete a null pointer
    static int n = argc; // zero-initialized to 0 then copy-initialized to argc
    std::cout << "n = " << n << '\n';
    A a = A(); // the effect is same as: A a{}; or A a = {};
    std::cout << "a = {" << a.a << ' ' << a.b << ' ' << a.c << "}\n";
}

