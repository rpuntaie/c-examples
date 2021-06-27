/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_binary_search.exe ./cpp/algorithm_binary_search.cpp && (cd ../_build/cpp/;./algorithm_binary_search.exe)
https://en.cppreference.com/w/cpp/algorithm/binary_search
*/
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> haystack {1, 3, 4, 5, 9};
    std::vector<int> needles {1, 2, 3};
    for (auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';
        if (std::binary_search(haystack.begin(), haystack.end(), needle)) {
            std::cout << "Found " << needle << '\n';
        } else {
            std::cout << "no dice!\n";
        }
    }
}

