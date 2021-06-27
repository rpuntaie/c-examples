/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_constraints.exe ./cpp/language_constraints.cpp && (cd ../_build/cpp/;./language_constraints.exe)
https://en.cppreference.com/w/cpp/language/constraints
*/
#include <string>
#include <cstddef>
#include <concepts>
// Declaration of the concept "Hashable", which is satisfied by any type 'T'
// such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
// compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};
struct meow {};
// Constrained C++20 function template:
template<Hashable T>
void f(T) {}
//
// Alternative ways to apply the same constraint:
// template<typename T>
//    requires Hashable<T>
// void f(T) {}
//
// template<typename T>
// void f(T) requires Hashable<T> {}
int main() {
  using std::operator""s;
  f("abc"s); // OK, std::string satisfies Hashable
//f(meow{}); // Error: meow does not satisfy Hashable
}

