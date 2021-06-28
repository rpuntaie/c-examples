/*
g++ -std=c++20 -o ../_build/r/tk.o -c r/tk.cpp
*/

#include <iostream>
#include <string>
#include <array>
#include <tuple>
#include <memory>

// ## Aggregates
struct S{
    int x{2};
    S(int) = delete;
};
struct X{
    int x;
    X() = default;
};
struct Y{
    int x;
    Y();
};
Y::Y() = default;
template<typename T, typename U>
struct TU{
    T t;
    U u;
};
template<typename T>
struct MyData{
    T data;
};
MyData(const char*) -> MyData<std::string>;
template<typename T, std::size_t N>
struct Array{
    T data[N];
};
void f(){
    //S s(1);     // always an error
    //S s2{1};    // OK in C++17, error in C++20, S is not an aggregate now
    //X x{1};     // OK in C++17, error in C++20
    //Y y{2};     // always an error
// deduction guide was needed in C++17
// template<typename T, typename U>
// TU(T, U) -> TU<T,U>;
TU u{1, 2.0};    // TU<int, double>
MyData s1{"abc"};   // OK, MyData<std::string> using deduction guide
MyData<int> s2{1};  // OK, explicit template argument
// MyData s3{1};       // Error, CTAD isn't involved
Array a{{1, 2, 3}}; // Array<int, 3>, notice additional braces
Array str{"hello"}; // Array<char, 6>
}

// ### brace elision
template<typename T, typename U>
struct Pair{
    T first;
    U second;
};
template<typename T, std::size_t N>
struct A1{
    T data[N];
    T oneMore;
    Pair<T, T> p;
};
template<typename T>
struct A2{
    T data[3];
    T oneMore;
    Pair<int, int> p;
};
void g(){
// A1::data is an array of dependent bound and A1::p is a dependent type, thus,
// no brace elision for them
A1 a1{{1,2,3}, 4, {5, 6}};  // A1<int, 3>
// A2::data is an array of non-dependent bound and A1::p is a non-dependent type,
// thus, brace elision works
A2 a2{1, 2, 3, 4, 5, 6};    // A2<int>
}


// ### pack expression without deduction guide
template<typename... Ts>
struct Overload : Ts...{
    using Ts::operator()...;
};
// no need for deduction guide anymore
Overload p{[](int){
        std::cout << "called with int";
    }, [](char){
        std::cout << "called with char";
    }
};     // Overload<lambda(int), lambda(char)>
void h(){
p(1);   // called with int
p('c'); // called with char
}

// ### pack expansions 
template<typename T, typename...Ts>
struct Pack : Ts... {
    T x;
};
// can deduce only the first element
Pack p1{1};         // Pack<int>
Pack p2{[]{}};      // Pack<lambda()>
//Pack p3{1, []{}};   // error
//


struct A{};
struct B{};
struct C{};
struct D{
    operator C(){return C{};}
};
template<typename...Ts>
struct P : std::tuple<Ts...>, Ts...{
};
void pp(){
auto a=P{std::tuple<A, B, C>{}, A{}, B{}, C{}}; // P<A, B, C>
// equivalent to the above, since pack elements were deduced for
// std::tuple<A, B, C> there's no need to repeat their types
auto b=P{std::tuple<A, B, C>{}, {}, {}, {}}; // P<A, B, C>
// since we know the whole P<A, B, C> type after std::tuple initializer, we can
// omit trailing initializers, elements will be value-initialized as usual
auto c=P{std::tuple<A, B, C>{}, {}, {}}; // P<A, B, C>
// error, pack deduced from first initializer is <A, B, C> but got <A, B, D> for
// the trailing pack, implicit conversions are not considered
//P{std::tuple<A, B, C>{}, {}, {}, D{}};
}

// ### Parenthesized initialization of aggregates
struct K{
    int a;
    int b = 2;
    struct K2{
        int d;
    } c;
};
struct Ref{
    const int& r;
};
int GetInt(){
    return 21;
}
void w(){
//K{0.1}; // error, narrowing
K(0.1); // OK
K{.a=1}; // OK
//K(.a=1); // error, no designated initializers
Ref r1{GetInt()}; // OK, lifetime is extended
Ref r2(GetInt()); // dangling, lifetime is not extended
K{1, 2, 3}; // OK, brace elision, same as K{1,2,{3}}
//K(1, 2, 3); // error, no brace elision
// values without initializers take default values or value-initialized(T{})
K{1}; // {1, 2, 0}
K(1); // {1, 2, 0}
// make_unique works now
auto ps = std::make_unique<K>(1, 2, K::K2{3});
// arrays are also supported
int arr1[](1, 2, 3);
int arr2[2](1); // {1, 0}
}
