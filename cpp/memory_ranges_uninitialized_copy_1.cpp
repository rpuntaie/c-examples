/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_copy_1.exe ./cpp/memory_ranges_uninitialized_copy_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_copy_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_copy
*/
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    const char* v[] { "This", "is", "an", "example", };
    if (const auto sz{std::size(v)};
        void* pbuf = std::aligned_alloc(alignof(std::string), sizeof(std::string) * sz))
    {
        try
        {
            auto first {static_cast<std::string*>(pbuf)};
            auto last {first + sz};
            std::ranges::uninitialized_copy(std::begin(v), std::end(v), first, last);
            std::cout << "{ ";
            for (auto it {first}; it != last; ++it)
                std::cout << std::quoted(*it) << ", ";
            std::cout << "};\n";
            std::ranges::destroy(first, last);
        }
        catch(...)
        {
            std::cout << "uninitialized_copy exception\n";
        }
        std::free(pbuf);
    }
}

