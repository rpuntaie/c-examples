/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_decay.exe ./cpp/types_decay.cpp && (cd ../_build/cpp/;./types_decay.exe)
https://en.cppreference.com/w/cpp/types/decay
*/
#include <iostream>
#include <type_traits>
template <typename T, typename U>
struct decay_equiv : 
    std::is_same<typename std::decay<T>::type, U>::type 
{};
int main()
{
    std::cout << std::boolalpha
              << decay_equiv<int, int>::value << '\n'
              << decay_equiv<int&, int>::value << '\n'
              << decay_equiv<int&&, int>::value << '\n'
              << decay_equiv<const int&, int>::value << '\n'
              << decay_equiv<int[2], int*>::value << '\n'
              << decay_equiv<int(int), int(*)(int)>::value << '\n';
}

