/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_fill_1.exe ./cpp/memory_ranges_uninitialized_fill_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_fill_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_fill
*/
#include <iostream>
#include <memory>
#include <string>
int main()
{
    constexpr int n {4};
    alignas(alignof(std::string)) char out[n * sizeof(std::string)];
    try
    {
        auto first {reinterpret_cast<std::string*>(out)};
        auto last {first + n};
        std::ranges::uninitialized_fill(first, last, "▄▀▄▀▄▀▄▀");
        int count {1};
        for (auto it {first}; it != last; ++it) {
            std::cout << count++ << ' ' << *it << '\n';
        }
        std::ranges::destroy(first, last);
    }
    catch(...)
    {
        std::cout << "Exception!\n";
    }
}

