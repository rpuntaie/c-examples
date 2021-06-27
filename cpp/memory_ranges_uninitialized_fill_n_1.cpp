/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_fill_n_1.exe ./cpp/memory_ranges_uninitialized_fill_n_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_fill_n_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_fill_n
*/
#include <iostream>
#include <memory>
#include <string>
int main()
{
    constexpr int n {3};
    alignas(alignof(std::string)) char out[n * sizeof(std::string)];
    try
    {
        auto first {reinterpret_cast<std::string*>(out)};
        auto last = std::ranges::uninitialized_fill_n(first, n, "cppreference");
        for (auto it {first}; it != last; ++it) {
            std::cout << *it << '\n';
        }
        std::ranges::destroy(first, last);
    }
    catch(...)
    {
        std::cout << "Exception!\n";
    }
}

