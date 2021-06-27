/*
g++ -std=c++20 -c r/ty.cpp
*/

#include <memory>

template<typename T> constexpr int f() { 
  //return T::value;  //error
  return 3;
}
template<bool B, typename T> void g(decltype(B ? f<T>() : 0));
template<bool B, typename T> void g(...);

template<bool B, typename T> void h(decltype(int{B ? f<T>() : 0}));
template<bool B, typename T> void h(...);

void x() {
    g<false, int>(0); // OK
    h<false, int>(0); // error
}

// ### Implicit creation of objects for low-level object manipulation {#fix-impl-creation}
struct X { int a, b; };
X *make_x() {
    X* p = (X*)malloc(sizeof(struct X));
    p->a = 1;   // UB in C++17, OK in C++20
    return p;
}

int f(){
    using T = int;
    T n{1};
    n.~T();     // no effect in C++17, ends n's lifetime in C++20
    return n;   // OK in C++17, UB in C++20, n is dead now
}
