/*
g++ -std=c++20 -o ../_build/r/tx.o -c r/tx.cpp
*/

#include <memory>
#include <tuple>
#include <vector>

std::tuple t{std::tuple{1, 2}};     // std::tuple<int, int>
std::vector v{std::vector{1,2,3}};  // std::vector<int>

// this example is from "C++17" book by N. Josuttis, section 9.1.1
// now it has consistent behavior across compilers
template<typename... Args>
auto make_vector(const Args&... elems)
{
    return std::vector{elems...};
}
auto v2 = make_vector(std::vector{1,2,3});  // std::vector<int>
// ### `const&`-qualified pointers to members
struct S {
    void f() const& {}
};
void _(){
S{}.f();        // OK
(S{}.*&S::f)(); // could be an error on some old compilers
}

// ### Simplifying implicit lambda capture {#fix-impl-capture}
struct SS{
    int x{1};
    int y{[&]{ return x + 1; }()};  // OK, captures 'this'
};

template<bool B>
void f1() {
    std::unique_ptr<int> p;
    [=]() {
        if constexpr (B) {
            (void)p;        // always captures p
        }
    }();
}
//f1<false>();    // error, can't capture unique_ptr by-value
void f2() {
    std::unique_ptr<int> p;
    // [=]() {
    //     typeid(p);  // error, can't capture unique_ptr by-value
    // }();
}
void f3() {
    std::unique_ptr<int> p;
    [=]() {
        sizeof(p);  // OK, unevaluated operand
    }();
}

// ### `const` mismatch with defaulted copy constructor
// 
struct NonConstCopyable{
    NonConstCopyable() = default;
    NonConstCopyable(NonConstCopyable&){}   // takes by non-const reference
    NonConstCopyable(NonConstCopyable&&){}
};
// std::tuple(const std::tuple& other) = default;   // takes by const reference
void ff(){
    std::tuple<NonConstCopyable> t; // error in C++17, OK in C++20
    //auto t2 = t;                    // always an error
    auto t3 = std::move(t);         // OK, move-ctor is used
}

// ### Access checking on specializations
// 
template<typename T>
void f(){}
template<typename T>
struct Trait{};
class C{
    class Impl; // private
};
template<>
struct Trait<C::Impl>{};    // OK
template struct Trait<C::Impl>; // OK
class C2{
    template<typename T>
    struct Impl;    // private
};
template<typename T>
struct Trait<C2::Impl<T>>;   // OK

// ### ADL and function templates that are not visible
int h;
void g();

namespace N {
	struct A {};
	template<class T> int f(T);
	template<class T> int g(T);
	template<class T> int h(T);
}
// OK: lookup of `f` finds nothing, `f` treated as a template name
auto a = f<N::A>(N::A{});
// OK: lookup of `g` finds a function, `g` treated as a template name
auto b = g<N::A>(N::A{});
// error: `h` is a variable, not a template function
// auto c = h<N::A>(N::A{};
// OK, `N::h` is qualified-id
auto d = N::h<N::A>(N::A{});


struct A {};
bool operator <(void (*fp)(), A);
void f(){}
int main() {
    A a;
    // f < a;      // OK until C++20, now error
    (f) < a;    // OK
}

// ### Specify when `constexpr` function definitions are needed for constant evaluation
struct duration {
    constexpr duration() {}
    constexpr operator int() const { return 0; }
};
// duration d = duration(); // #1
int n = sizeof(short{duration(duration())});    // always OK since C++20


