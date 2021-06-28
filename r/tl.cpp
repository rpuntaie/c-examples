/*
g++ -std=c++20 -o ../_build/r/tl.o -c r/tl.cpp
*/

#include <string>
#include <cstring>
#include <iostream>
#include <assert.h>

template<std::size_t N>
struct fixed_string{
    constexpr fixed_string(const char (&s)[N+1]) {
        std::copy_n(s, N + 1, str);
    }
    constexpr const char* data() const {
        return str;
    }
    constexpr std::size_t size() const {
        return N;
    }

    char str[N+1];
};

template<std::size_t N>
fixed_string(const char (&)[N])->fixed_string<N-1>;

// user-defined literals are also supported
template<fixed_string S>
constexpr auto operator""_cts(){
    return S;
}

// N for `S` will be deduced
template<fixed_string S>
void f(){
    std::cout << S.data() << ", " << S.size() << '\n';
}

void w(){
f<"abc">(); // abc, 3
constexpr auto s = "def"_cts;
f<s>();     // def, 3
}


template<auto T>    // placeholder for any non-type template parameter
struct X{};
template<typename T, std::size_t N>
struct Arr{
    T data[N];
};
void v(){
X<5> x1;
X<'c'> x2;
X<1.2> x3;
// with the help of CTAD (class template argument decution) for aggregates
X<Arr{{1,2,3}}> x4; // X<Arr<int, 3>>
X<Arr{"hi"}> x5;    // X<Arr<char, 3>>
}


template<auto T>
struct S{};

union U{
    int a;
    int b;
};

enum class E{
    A = 0,
    B = 0
};

struct C{
    int x;
    bool operator==(const C&) const{    // never equal
        return false;
    }
};

void z(){
constexpr C c1{1};
constexpr C c2{1};
assert(c1 != c2);                           // not equal using operator==()
assert(std::memcmp(&c1, &c2, sizeof(C)) == 0);   // but equal bitwise
// thus, equal at compile-time, operator==() is not used
static_assert(std::is_same_v<S<c1>, S<c2>>);

constexpr E e1{E::A};
constexpr E e2{E::B};
// equal bitwise, enum's identity isn't taken into account
assert(std::memcmp(&e1, &e2, sizeof(E)) == 0);
static_assert(std::is_same_v<S<e1>, S<e2>>); // thus, equal at compile-time

constexpr U u1{.a=1};
constexpr U u2{.b=1};
// equal bitwise but have different active members(a vs. b)
assert(std::memcmp(&u1, &u2, sizeof(U)) == 0);
// thus, not equal at compile-time
static_assert(!std::is_same_v<S<u1>, S<u2>>);
}


//
//template<typename T, typename U>
//struct S{
//    T t;
//    U u;
//};
//// deduction guide was needed in C++17
//// template<typename T, typename U>
//// S(T, U) -> S<T,U>;
//S s{1, 2.0};    // S<int, double>
//
////
//template<typename T>
//struct MyData{
//    T data;
//};
//MyData(const char*) -> MyData<std::string>;
//void u(){
//MyData s1{"abc"};   // OK, MyData<std::string> using deduction guide
//MyData<int> s2{1};  // OK, explicit template argument
////MyData s3{1};       // Error, CTAD isn't involved
//}
//
//
//template<typename T, std::size_t N>
//struct Array{
//    T data[N];
//};
//Array a{{1, 2, 3}}; // Array<int, 3>, notice additional braces
//Array str{"hello"}; // Array<char, 6>
//
//
//
//template<typename T, typename U>
//struct Pair{
//    T first;
//    U second;
//};
//
//template<typename T, std::size_t N>
//struct A1{
//    T data[N];
//    T oneMore;
//    Pair<T, T> p;
//};
//
//template<typename T>
//struct A2{
//    T data[3];
//    T oneMore;
//    Pair<int, int> p;
//};
//
//void z(){
//// A1::data is an array of dependent bound and A1::p is a dependent type, thus,
//// no brace elision for them
//A1 a1{{1,2,3}, 4, {5, 6}};  // A1<int, 3>
//// A2::data is an array of non-dependent bound and A1::p is a non-dependent type,
//// thus, brace elision works
//A2 a2{1, 2, 3, 4, 5, 6};    // A2<int>
//}
