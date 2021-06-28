/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_member_access_2.exe ./cpp/language_operator_member_access_2.cpp && (cd ../_build/cpp/;./language_operator_member_access_2.exe)
https://en.cppreference.com/w/cpp/language/operator_member_access
*/
void f(int) {}
void f(double) {}
struct A { int i; };
struct B { void f(){}; };
int main()
{
    int n = 1;
    int* pn = &n; // pointer
    int* pn2 = &*pn; // pn2 == pn
    int A::* mp = &A::i; // pointer to data member
    void (B::*mpf)() = &B::f; // pointer to member function
    void (*pf)(int) = &f; // overload resolution due to initialization context
//  auto pf2 = &f; // error: ambiguous overloaded function type
    auto pf2 = static_cast<void (*)(int)>(&f); // overload resolution due to cast
}

