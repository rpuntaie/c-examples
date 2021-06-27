/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_template_parameters_21.exe ./cpp/language_template_parameters_21.cpp && (cd ../_build/cpp/;./language_template_parameters_21.exe)
https://en.cppreference.com/w/cpp/language/template_parameters
*/
#include <iostream>
// simple non-type template parameter
template<int N>
struct S { int a[N]; };
template<const char*>
struct S2 {};
// complicated non-type example
template
<
    char c, // integral type
    int (&ra)[5], // lvalue reference to object (of array type)
    int (*pf)(int), // pointer to function
    int (S<10>::*a)[10] // pointer to member object (of type int[10])
> struct Complicated
{
    // calls the function selected at compile time
    // and stores the result in the array selected at compile time
    void foo(char base)
    {
        ra[4] = pf(c - base);
    }
};
S2<"fail"> s2; // error: string literal cannot be used
char okay[] = "okay"; // static object with linkage
S2< &okay[0] > s2; // error: array element has no linkage
S2<okay> s2; // works
int a[5];
int f(int n) { return n; }
int main()
{
    S<10> s; // s.a is an array of 10 int
    s.a[9] = 4;
    Complicated<'2', a, f, &S<10>::a> c;
    c.foo('0');
    std::cout << s.a[9] << a[4] << '\n';
}

