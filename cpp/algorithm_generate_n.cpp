/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_generate_n.exe ./cpp/algorithm_generate_n.cpp && (cd ../_build/cpp/;./algorithm_generate_n.exe)
https://en.cppreference.com/w/cpp/algorithm/generate_n
*/
#include <random>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
int main()
{
    std::mt19937 rng; // default constructed, seeded with fixed seed
    std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                    5, std::ref(rng));
    std::cout << '\n';
}

