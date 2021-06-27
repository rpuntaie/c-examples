/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_functions_2.exe ./cpp/language_member_functions_2.cpp && (cd ../_build/cpp/;./language_member_functions_2.exe)
https://en.cppreference.com/w/cpp/language/member_functions
*/
struct S {
    static int n;
    void f();
};
void S::f() {
    n = 1; // transformed to S::n = 1;
}
int main() {
    S s1, s2;
    s1.f(); // changes S::n
}

