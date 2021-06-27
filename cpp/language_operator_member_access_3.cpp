/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_member_access_3.exe ./cpp/language_operator_member_access_3.cpp && (cd ../_build/cpp/;./language_operator_member_access_3.exe)
https://en.cppreference.com/w/cpp/language/operator_member_access
*/
#include <iostream>
struct P
{
    template<typename T>
    static T* ptr() { return new T; }
};
template<typename T>
struct A
{
    A(int n): n(n) {}
    int n;
    static int sn;
    int f() { return 10 + n; }
    static int sf() { return 4; }
    class B {};
    enum E {RED = 1, BLUE = 2};
    void g()
    {
        typedef int U;
        // keyword template needed for a dependent template member
        int* p = T().template ptr<U>();
        p->~U(); // U is int, calls int's pseudo destructor
        delete p;
    }
};
template<> int A<P>::sn = 2;
int main()
{
    A<P> a(1);
    std::cout << a.n << ' '
              << a.sn << ' '   // A::sn also works
              << a.f() << ' ' 
              << a.sf() << ' ' // A::sf() also works
//            << a.B << ' '    // error: nested type not allowed
              << a.RED << ' '; // enumerator
}

