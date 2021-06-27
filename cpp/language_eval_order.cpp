/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_eval_order.exe ./cpp/language_eval_order.cpp && (cd ../_build/cpp/;./language_eval_order.exe) || true
https://en.cppreference.com/w/cpp/language/eval_order
*/
#include <cstdio>
int a() { return std::puts("a"); }
int b() { return std::puts("b"); }
int c() { return std::puts("c"); }
void z(int, int, int) {}
int main() {
    z(a(), b(), c());       // all 6 permutations of output are allowed
    return a() + b() + c(); // all 6 permutations of output are allowed
}

