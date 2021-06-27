/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_pair_tuple_size.exe ./cpp/utility_pair_tuple_size.cpp && (cd ../_build/cpp/;./utility_pair_tuple_size.exe)
https://en.cppreference.com/w/cpp/utility/pair/tuple_size
*/
#include <iostream>
#include <utility>
#include <tuple>
template<class T>
void test(T t)
{
    int a[std::tuple_size<T>::value]; // can be used at compile time
    std::cout << std::tuple_size<T>::value << '\n'; // or at run time
}
int main()
{
    test(std::make_tuple(1, 2, 3.14));
    test(std::make_pair(1, 3.14));
}

