/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_value_construct_n_1.exe ./cpp/memory_ranges_uninitialized_value_construct_n_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_value_construct_n_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_value_construct_n
*/
#include <iostream>
#include <memory>
#include <string>
int main()
{
    struct S { std::string m{ "█▓▒░ █▓▒░ █▓▒░ " }; };
    constexpr int n {4};
    alignas(alignof(S)) char out[n * sizeof(S)];
    try
    {
        auto first {reinterpret_cast<S*>(out)};
        auto last = std::ranges::uninitialized_value_construct_n(first, n);
        auto count {1};
        for (auto it {first}; it != last; ++it) {
            std::cout << count++ << ' ' << it->m << '\n';
        }
        std::ranges::destroy(first, last);
    }
    catch(...)
    {
        std::cout << "Exception!\n";
    }
    // Notice that for "trivial types" the uninitialized_value_construct_n
    // zero-initializes the given uninitialized memory area.
    int v[] { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::cout << ' ';
    for (const int i : v) { std::cout << i << ' '; }
    std::cout << "\n ";
    std::ranges::uninitialized_value_construct_n(std::begin(v), std::size(v));
    for (const int i : v) { std::cout << i << ' '; }
    std::cout << '\n';
}

