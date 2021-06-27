/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_swap.exe ./cpp/container_array_swap.cpp && (cd ../_build/cpp/;./container_array_swap.exe)
https://en.cppreference.com/w/cpp/container/array/swap
*/
#include <array>
#include <iostream>
template<class Os, class V> Os& operator<<(Os& os, const V& v) {
    os << "{";
    for (auto i : v) os << ' ' << i;
    return os << " } ";
}
int main()
{
    std::array<int, 3> a1{1, 2, 3}, a2{4, 5, 6};
    auto it1 = a1.begin();
    auto it2 = a2.begin();
    int& ref1 = a1[1];
    int& ref2 = a2[1];
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    a1.swap(a2);
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    // Note that after swap iterators and references stay associated with their original
    // array, e.g. `it1` still points to element a1[0], `ref1` still refers to a1[1].
}

