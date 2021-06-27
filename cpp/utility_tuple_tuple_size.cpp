/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_tuple_size.exe ./cpp/utility_tuple_tuple_size.cpp && (cd ../_build/cpp/;./utility_tuple_tuple_size.exe)
https://en.cppreference.com/w/cpp/utility/tuple/tuple_size
*/
#include <iostream>
#include <tuple>
template <class T>
void test(T value)
{
    int a[std::tuple_size_v<T>]; // can be used at compile time
    std::cout << std::tuple_size<T>{} << ' ' // or at run time
              << sizeof a << ' ' 
              << sizeof value << '\n';
}
int main()
{
    test(std::make_tuple(1, 2, 3.14));
}

