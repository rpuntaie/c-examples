/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_make_from_tuple.exe ./cpp/utility_make_from_tuple.cpp && (cd ../_build/cpp/;./utility_make_from_tuple.exe)
https://en.cppreference.com/w/cpp/utility/make_from_tuple
*/
#include <iostream>
#include <tuple>
struct Foo {
    Foo(int first, float second, int third) {
        std::cout << first << ", " << second << ", " << third << "\n";
    }
};
int main()
{
   auto tuple = std::make_tuple(42, 3.14f, 0);
   std::make_from_tuple<Foo>(std::move(tuple));
}

