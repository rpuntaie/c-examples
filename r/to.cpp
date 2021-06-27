/*
g++ -std=c++20 -c r/to.cpp
*/

#include <string>

struct S{
    int x;
    int y{2};
    std::string s;
};
void nn(){
S s1{.y = 3};   // {0, 3, {}}
S s2 = {.x = 1, .s = "abc"};    // {1, 2, {"abc"}}
//S s3{.y = 1, .x = 2};   // Error, x should be initialized before y
}


struct U{
    int a : 1;
    int b : 1;
    U() : a{0}, b{1}{}
};
// since C++20:
struct V{
    int a : 1 {0};
    int b : 1 = 1;
};


template <class T>
T::R f();  // OK, return type of a function declaration at global scope
//template <class T>
//void f(T::R);   // Ill-formed (no diagnostic required), attempt to declare a
template<typename T>
struct PtrTraits{
    using Ptr = void*;
};
template <class T>
struct P {
  using Ptr = PtrTraits<T>::Ptr;  // OK, in a defining-type-id
  T::R f(T::P p) {                // OK, class scope
    return static_cast<T::R>(p);  // OK, type-id of a static_cast
  }
  auto g() -> P<T*>::Ptr;         // OK, trailing-return-type
  T::SubType t;
};
template <typename T>
void f() {
  void (*pf)(T::X);   // Variable pf of type void* initialized with T::X
  //void g(T::X);     // Error: T::X at block scope does not denote a type
                      // (attempt to declare a void variable)
}


// C++20
namespace A::B::inline C{
    void f2(){}
}
// C++17
namespace A::B{
    inline namespace C{
        void f1(){}
    }
}
