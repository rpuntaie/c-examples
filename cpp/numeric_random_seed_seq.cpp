/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_seed_seq.exe ./cpp/numeric_random_seed_seq.cpp && (cd ../_build/cpp/;./numeric_random_seed_seq.exe)
https://en.cppreference.com/w/cpp/numeric/random/seed_seq
*/
#include <random>
#include <cstdint>
#include <iostream>
int main()
{
    std::seed_seq seq{1,2,3,4,5};
    std::vector<std::uint32_t> seeds(10);
    seq.generate(seeds.begin(), seeds.end());
    for (std::uint32_t n : seeds) {
        std::cout << n << '\n';
    }
}

