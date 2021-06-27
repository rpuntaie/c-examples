/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_member_access_1.exe ./cpp/language_operator_member_access_1.cpp && (cd ../_build/cpp/;./language_operator_member_access_1.exe)
https://en.cppreference.com/w/cpp/language/operator_member_access
*/
#include <iostream>
int f() { return 42; }
int main()
{
    int n = 1;
    int* pn = &n;
    int& r = *pn;  // lvalue can be bound to a reference
    int m = *pn;   // indirection + lvalue-to-rvalue conversion
    int (*fp)() = &f;
    int (&fr)() = *fp; // function lvalue can be bound to a reference 
}

