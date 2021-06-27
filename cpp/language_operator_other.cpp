/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_other.exe ./cpp/language_operator_other.cpp && (cd ../_build/cpp/;./language_operator_other.exe)
https://en.cppreference.com/w/cpp/language/operator_other
*/
#include <cstdio>
struct S
{
    int f1(double d) {
        return printf("%f \n", d); // variable argument function call
    }
    int f2() {
        return f1(7); // member function call, same as this->f1()
                      // integer argument converted to double
    }
};
void f() {
   puts("function called"); // function call
}
int main()
{
    f(); // function call
    S s;
    s.f2(); // member function call
}

