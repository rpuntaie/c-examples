/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_virtual_4.exe ./cpp/language_virtual_4.cpp && (cd ../_build/cpp/;./language_virtual_4.exe)
https://en.cppreference.com/w/cpp/language/virtual
*/
struct B {
    virtual void f();
};
struct D : B {
    void f(int); // D::f hides B::f (wrong parameter list)
};
struct D2 : D {
    void f(); // D2::f overrides B::f (doesn't matter that it's not visible)
};
int main()
{
    B b;   B& b_as_b   = b;
    D d;   B& d_as_b   = d;    D& d_as_d = d;
    D2 d2; B& d2_as_b  = d2;   D& d2_as_d = d2;
    b_as_b.f(); // calls B::f()
    d_as_b.f(); // calls B::f()
    d2_as_b.f(); // calls D2::f()
    d_as_d.f(); // Error: lookup in D finds only f(int)
    d2_as_d.f(); // Error: lookup in D finds only f(int)
}

