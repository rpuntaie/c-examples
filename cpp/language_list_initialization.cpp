/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_list_initialization.exe ./cpp/language_list_initialization.cpp && (cd ../_build/cpp/;./language_list_initialization.exe)
https://en.cppreference.com/w/cpp/language/list_initialization
*/
#include <initializer_list>
struct X {}; // aggregate
struct Q { // non-aggregate
    Q() = default;
    Q(Q const&) = default;
    Q(std::initializer_list<Q>) {}
};
int main() {
  X x;
  X x2 = X { x }; // copy-constructor (not aggregate initialization)
  Q q;
  Q q2 = Q { q }; // initializer-list constructor (not copy constructor)
}

