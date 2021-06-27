/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_bind_front_1.exe ./cpp/utility_functional_bind_front_1.cpp && (cd ../_build/cpp/;./utility_functional_bind_front_1.exe)
https://en.cppreference.com/w/cpp/utility/functional/bind_front
*/
#include <functional>
#include <iostream>
int minus(int a, int b){
    return a-b;
}
int main()
{
    auto fifty_minus = std::bind_front(minus, 50);
    std::cout << fifty_minus (3);
}

