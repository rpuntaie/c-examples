/*
g++ -std=c++20 -o ../_build/r/tu.o -c r/tu.cpp
*/

#include<memory>
#include<string>

template <typename T>
std::unique_ptr<T> f0(std::unique_ptr<T> && ptr) {
    return ptr; // copied in C++17(thus, error), moved in C++20, OK
}

std::string f1(std::string && x) {
    return x;   // copied in C++17, moved in C++20
}

struct Widget{};

void f2(Widget w){
    throw w;    // copied in C++17, moved in C++20
}

struct From {
    From(Widget const &);
    From(Widget&&);
};

struct To {
    operator Widget() const &;
    operator Widget() &&;
};

From f3() {
    Widget w;
    return w;  // moved (no NRVO because of different types)
}

Widget f4() {
    To t;
    return t;// copied in C++17(conversions were not considered), moved in C++20
}

struct A{
    A(const Widget&);
    A(Widget&&);
};

struct B{
    B(Widget);
};

A f5() {
    Widget w;
    return w;  // moved
}

B f6() {
    Widget w;
    return w; // copied in C++17(because there's no B(Widget&&)), moved in C++20
}

struct Derived : Widget{};

std::shared_ptr<Widget> f7() {
    std::shared_ptr<Derived> result;
    return result;  // moved
}

Widget f8() {
    Derived result;
    // copied in C++17(because there's no Base(Derived)), moved in C++20
    return result;
}
