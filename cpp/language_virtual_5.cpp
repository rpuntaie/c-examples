/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_virtual_5.exe ./cpp/language_virtual_5.cpp && (cd ../_build/cpp/;./language_virtual_5.exe)
https://en.cppreference.com/w/cpp/language/virtual
*/
class B {};
struct Base {
    virtual void vf1(){};
    virtual void vf2(){};
    virtual void vf3(){};
    virtual B* vf4(){return new B{};};
    virtual B* vf5(){return new B{};};
};
class D : private B {
    friend struct Derived; // in Derived, B is an accessible base of D
};
class A; // forward-declared class is an incomplete type
struct Derived : public Base {
    void vf1(){};    // virtual, overrides Base::vf1()
    void vf2(int){}; // non-virtual, hides Base::vf2()
//  char vf3();    // Error: overrides Base::vf3, but has different
                   // and non-covariant return type
    D* vf4(){return new D{};};      // overrides Base::vf4() and has covariant return type
//  A* vf5();      // Error: A is incomplete type
};
int main()
{
    Derived d;
    Base& br = d;
    Derived& dr = d;
    br.vf1(); // calls Derived::vf1()
    br.vf2(); // calls Base::vf2()
//  dr.vf2(); // Error: vf2(int) hides vf2()
    B* p = br.vf4(); // calls Derived::vf4() and converts the result to B*
    D* q = dr.vf4(); // calls Derived::vf4() and does not convert
                     //  the result to B*
}

