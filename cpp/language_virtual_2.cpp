/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_virtual_2.exe ./cpp/language_virtual_2.cpp && (cd ../_build/cpp/;./language_virtual_2.exe)
https://en.cppreference.com/w/cpp/language/virtual
*/
struct A { virtual void f(){}; };     // A::f is virtual
struct B : A { void f(){}; };         // B::f overrides A::f in B
struct C : virtual B { void f(){}; }; // C::f overrides A::f in C
struct D : virtual B {}; // D does not introduce an overrider, B::f is final in D
struct E : C, D  {       // E does not introduce an overrider, C::f is final in E
    using A::f; // not a function declaration, just makes A::f visible to lookup
};
int main() {
   E e;
   e.f();    // virtual call calls C::f, the final overrider in e
   e.E::f(); // non-virtual call calls A::f, which is visible in E
}

