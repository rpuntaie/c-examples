/*
g++ -std=c++20 -o ../_build/r/ti.o -c r/ti.cpp
*/

#include <concepts>
#include <functional>
#include <vector>
#include <string>
#include <map>

struct S{
    void f(){
        [=]{};          // captures this by reference, deprecated since C++20
        [=, *this]{};   // OK since C++17, captures this by value
        [=, this]{};    // OK since C++20, captures this by reference
    }
};
void w(){
// lambda that expect std::vector<T>
// until C++20:
[](auto vector){
    using T =typename decltype(vector)::value_type;
    // use T
};
// since C++20:
[]<typename T>(std::vector<T> vector){
    // use T
};

// access argument type
// until C++20
[](const auto& x){
    using T = std::decay_t<decltype(x)>;
    // using T = decltype(x); // without decay_t<> it would be const T&, so
    T copy = x;               // copy would be a reference type
    T::static_function();     // and these wouldn't work at all
    using Iterator = typename T::iterator;
};
// since C++20
[]<typename T>(const T& x){
    T copy = x;
    T::static_function();
    using Iterator = typename T::iterator;
};

// perfect forwarding
// until C++20:
[](auto&&... args){
    return f(std::forward<decltype(args)>(args)...);
};
// since C++20:
[]<typename... Ts>(Ts&&... args){
    return f(std::forward<Ts>(args)...);
};

// and of course you can mix them with auto-parameters
[]<typename T>(const T& a, auto b){};
}

// ### Lambdas in unevaluated contexts {#lambda-uneval-ctx}
using L = decltype([]{});   // lambdas have no linkage
L PublicApi();              // L can't be used for external linkage

// in template , two different declarations
template<class T> void f(decltype([]{}) (*s)[sizeof(T)]);
template<class T> void f(decltype([]{}) (*s)[sizeof(T)]);

// again, lambda types are never equivalent
static decltype([]{}) f();
//static decltype([]{}) f(); // error, return type mismatch

static decltype([]{}) g();
static decltype(g()) g(); // okay, redeclaration

// each specialization has its own lambda with unique type
template<typename T>
using R = decltype([]{});

static_assert(!std::is_same_v<R<int>, R<char>>);

// Lambda-based SFINAE and constraints are not supported, it just fails
template <class T>
auto f(T) -> decltype([]() { T::invalid; } ());
void f(...);

template<typename T>
void g(T) requires requires{
    [](){typename T::invalid x;}; }
{}
void g(...){}

//f(0);  // error
//g(0);  // error


// ### Default constructible and assignable stateless lambdas {#lambda-def-ctor}
auto greater = [](auto x,auto y)
{
    return x > y;
};
// requires default constructible type
std::map<std::string, int, decltype(greater)> map;
auto map2 = map;    // requires default assignable type

// ### Pack expansion in lambda init-capture {#lambda-pack-exp}
void u(int, int){}

//// C++17
//template<class F, class... Args>
//auto delay_apply(F&& f, Args&&... args) {
//    return [f=std::forward<F>(f), tup=std::make_tuple(std::forward<Args>(args)...)]()
//            -> decltype(auto) {
//        return std::apply(f, tup);
//    };
//}

// C++20
template<typename F, typename... Args>
auto delay_call(F&& f, Args&&... args) {
    return [f = std::forward<F>(f), ...f_args=std::forward<Args>(args)]()
            -> decltype(auto) {
        return f(f_args...);
    };
}

void dc(){
    delay_call(u, 1, 2)();
}

