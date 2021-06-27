/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_tuple_size.exe ./cpp/container_array_tuple_size.cpp && (cd ../_build/cpp/;./container_array_tuple_size.exe)
https://en.cppreference.com/w/cpp/container/array/tuple_size
*/
#include <iostream>
#include <array>
template<class T>
void test(T)
{
    int a[std::tuple_size<T>::value]; // can be used at compile time
    std::cout << std::size(a) << '\n';
}
int main()
{
    std::array<float, 3> arr;
    test(arr);
}

