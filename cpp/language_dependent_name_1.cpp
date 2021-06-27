/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_dependent_name_1.exe ./cpp/language_dependent_name_1.cpp && (cd ../_build/cpp/;./language_dependent_name_1.exe)
https://en.cppreference.com/w/cpp/language/dependent_name
*/
#include <iostream>
void g(double) { std::cout << "g(double)\n"; }
template<class T>
struct S {
    void f() const {
        g(1); // "g" is a non-dependent name, bound now
    }
};
void g(int) { std::cout << "g(int)\n"; }
int main()
{
    g(1); // calls g(int)
    S<int> s;
    s.f(); // calls g(double)
}

