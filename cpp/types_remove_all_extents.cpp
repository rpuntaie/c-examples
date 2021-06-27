/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_remove_all_extents.exe ./cpp/types_remove_all_extents.cpp && (cd ../_build/cpp/;./types_remove_all_extents.exe)
https://en.cppreference.com/w/cpp/types/remove_all_extents
*/
#include <iostream>
#include <type_traits>
#include <typeinfo>
template<class A>
void foo(const A&)
{
    typedef typename std::remove_all_extents<A>::type Type;
    std::cout << "underlying type: " << typeid(Type).name() << '\n';
}
int main()
{
    float a1[1][2][3];
    int a2[3][2];
    float a3[1][1][1][1][2];
    double a4[2][3];
    foo(a1);
    foo(a2);
    foo(a3);
    foo(a4);
}

