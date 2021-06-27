/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_functions_1.exe ./cpp/language_member_functions_1.cpp && (cd ../_build/cpp/;./language_member_functions_1.exe)
https://en.cppreference.com/w/cpp/language/member_functions
*/
struct S {
    int n;
    void f();
};
void S::f() {
    n = 1; // transformed to (*this).n = 1;
}
int main() {
    S s1, s2;
    s1.f(); // changes s1.n
}

