/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_explicit_cast.exe ./cpp/language_explicit_cast.cpp && (cd ../_build/cpp/;./language_explicit_cast.exe)
https://en.cppreference.com/w/cpp/language/explicit_cast
*/
double f = 3.14;
unsigned int n1 = (unsigned int)f; // C-style cast
unsigned int n2 = unsigned(f);     // functional cast
class C1;
class C2;
C2* foo(C1* p)
{
    return (C2*)p; // casts incomplete type to incomplete type
}
// In this example, C-style cast is interpreted as static_cast
// even though it would work as reinterpret_cast
struct A {};
struct I1 : A {};
struct I2 : A {};
struct D : I1, I2 {};
int main()
{
    D* d = nullptr;
//  A* a = (A*)d;                   // compile-time error
    A* a = reinterpret_cast<A*>(d); // this compiles
}

