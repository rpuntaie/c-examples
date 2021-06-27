/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_copy_n_1.exe ./cpp/memory_ranges_uninitialized_copy_n_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_copy_n_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_copy_n
*/
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    const char* stars[] { "Procyon", "Spica", "Pollux", "Deneb", "Polaris", };
    constexpr int n {4};
    alignas(alignof(std::string)) char out[n * sizeof(std::string)];
    try
    {
        auto first {reinterpret_cast<std::string*>(out)};
        auto last {first + n};
        auto ret {std::ranges::uninitialized_copy_n(std::begin(stars), n, first, last)};
        std::cout << "{ ";
        for (auto it {first}; it != ret.out; ++it)
            std::cout << std::quoted(*it) << ", ";
        std::cout << "};\n";
        std::ranges::destroy(first, last);
    }
    catch(...)
    {
        std::cout << "uninitialized_copy_n exception\n";
    }
}

