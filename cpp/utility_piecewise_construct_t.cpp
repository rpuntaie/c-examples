/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_piecewise_construct_t.exe ./cpp/utility_piecewise_construct_t.cpp && (cd ../_build/cpp/;./utility_piecewise_construct_t.exe)
https://en.cppreference.com/w/cpp/utility/piecewise_construct_t
*/
#include <iostream>
#include <utility>
#include <tuple>
struct Foo {
    Foo(std::tuple<int, float>) 
    {
        std::cout << "Constructed a Foo from a tuple\n";
    }
    Foo(int, float) 
    {
        std::cout << "Constructed a Foo from an int and a float\n";
    }
};
int main()
{
    std::tuple<int, float> t(1, 3.14);
    std::pair<Foo, Foo> p1(t, t);
    std::pair<Foo, Foo> p2(std::piecewise_construct, t, t);
}

