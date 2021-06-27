/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_swap.exe ./cpp/container_unordered_map_swap.cpp && (cd ../_build/cpp/;./container_unordered_map_swap.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/swap
*/
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
// print out a std::pair
template <class Os, class U, class V>
Os& operator<<(Os& os, const std::pair<U, V>& p) {
    return os << p.first << ":" << p.second;
}
// print out a container
template <class Os, class Co>
Os& operator<<(Os& os, const Co& co) {
    os << "{";
    for (auto const& i : co) { os << ' ' << i; }
    return os << " }\n";
}
int main()
{
    std::unordered_map<std::string, std::string>
        m1 { {"γ", "gamma"}, {"β", "beta"}, {"α", "alpha"}, {"γ", "gamma"}, },
        m2 { {"ε", "epsilon"}, {"δ", "delta"}, {"ε", "epsilon"} };
    const auto& ref = *(m1.begin());
    const auto iter = std::next(m1.cbegin());
    std::cout << "──────── before swap ────────\n"
              << "m1: " << m1 << "m2: " << m2 << "ref: " << ref
              << "\niter: " << *iter << '\n';
    m1.swap(m2);
    std::cout << "──────── after swap ────────\n"
              << "m1: " << m1 << "m2: " << m2 << "ref: " << ref
              << "\niter: " << *iter << '\n';
    // Note that every iterator referring to an element in one container before
    // the swap refers to the same element in the other container after the swap.
    // Same is true for references.
}

