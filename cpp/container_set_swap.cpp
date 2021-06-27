/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_swap.exe ./cpp/container_set_swap.cpp && (cd ../_build/cpp/;./container_set_swap.exe)
https://en.cppreference.com/w/cpp/container/set/swap
*/
#include <functional>
#include <iostream>
#include <set>
template<class Os, class Co> Os& operator<<(Os& os, const Co& co) {
    os << "{";
    for (auto const& i : co) { os << ' ' << i; }
    return os << " } ";
}
int main()
{
    std::set<int> a1{3, 1, 3, 2}, a2{5, 4, 5};
    auto it1 = std::next(a1.begin());
    auto it2 = std::next(a2.begin());
    const int& ref1 = *(a1.begin());
    const int& ref2 = *(a2.begin());
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    a1.swap(a2);
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    // Note that every iterator referring to an element in one container before the swap
    // refers to the same element in the other container after the swap. Same is true
    // for references.
    struct Cmp : std::less<int> {
        int id{};
        Cmp(int i) : id{i} { }
    };
    std::set<int, Cmp> s1{ {2, 2, 1, 1}, Cmp{6} }, s2{ {4, 4, 3, 3}, Cmp{9} };
    std::cout << s1 << s2 << s1.key_comp().id << ' ' << s2.key_comp().id << '\n';
    s1.swap(s2);
    std::cout << s1 << s2 << s1.key_comp().id << ' ' << s2.key_comp().id << '\n';
    // So, comparator objects (Cmp) are also exchanged after the swap.
}

