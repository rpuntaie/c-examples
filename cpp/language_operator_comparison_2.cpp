/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_comparison_2.exe ./cpp/language_operator_comparison_2.cpp && (cd ../_build/cpp/;./language_operator_comparison_2.exe)
https://en.cppreference.com/w/cpp/language/operator_comparison
*/
#include <iostream>
struct Foo  { int n1; int n2; };
union Union { int n; double d; };
int main()
{
    std::cout << std::boolalpha;
    char a[4] = "abc";
    char* p1 = &a[1];
    char* p2 = &a[2];
    std::cout << "Pointers to array elements:\n"
              << "p1 == p2? " << (p1 == p2) << '\n'
              << "p1 <  p2? " << (p1 <  p2) << '\n';
    Foo f;
    int* p3 = &f.n1;
    int* p4 = &f.n2;
    std::cout << "Pointers to members of a class:\n"
              << "p3 == p4? " << (p3 == p4) << '\n'
              << "p3 <  p4? " << (p3 <  p4) << '\n';
    Union u;
    int* p5 = &u.n;
    double* p6 = &u.d;
    std::cout << "Pointers to members of a union:\n"
              << "p5 == (void*)p6? " << (p5 == (void*)p6) << '\n'
              << "p5 <  (void*)p6? " << (p5 <  (void*)p6) << '\n';
}

