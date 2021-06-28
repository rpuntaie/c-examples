/*
g++ -std=c++20 -o ../_build/r/tc.o -c r/tc.cpp
*/

#include <concepts>

template<typename T>
concept is_sortable = true;

auto l = [](auto x){};
void f1(auto x){}               // unconstrained template
void f2(is_sortable auto x){}   // constrained template

template<is_sortable auto NonTypeParameter, is_sortable TypeParameter>
is_sortable auto f3(is_sortable auto x, auto y)
{
    // notice that nothing is allowed between constraint name and `auto`
    is_sortable auto z = 0;
    return 0;
}

template<is_sortable auto... NonTypePack, is_sortable... TypePack>
void f4(TypePack... args){}

int f();

// takes two parameters
template<typename T1, typename T2>
concept C = true;
// binds second parameter
C<double> auto v = f(); // means C<int, double>

struct X{
    operator is_sortable auto() {
        return 0;
    }
};

auto f5() -> is_sortable decltype(auto){
    f4<1,2,3>(1,2,3);
    return new is_sortable auto(1);
}

