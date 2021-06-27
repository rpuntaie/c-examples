/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_minmax_1.exe ./cpp/algorithm_ranges_minmax_1.cpp && (cd ../_build/cpp/;./algorithm_ranges_minmax_1.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/minmax
*/
#include <algorithm>
#include <iostream>
#include <random>
#include <array>
int main()
{
    namespace ranges = std::ranges;
    constexpr std::array v{3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(0, ranges::distance(v)); // [0..9]
    // auto bounds = ranges::minmax(distribution(generator), distribution(generator));
    // UB: dangling references: bounds.min and bounds.max have the type `const int&`.
    const int x1 = distribution(generator);
    const int x2 = distribution(generator);
    auto bounds = ranges::minmax(x1, x2); // OK: got references to lvalues x1 and x2
    std::cout << "v[" << bounds.min << ":" << bounds.max << "]: ";
    for (int i = bounds.min; i < bounds.max; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
    auto [min, max] = ranges::minmax(v);
    std::cout << "smallest: " << min << ", " << "largest: " << max << '\n';
}

