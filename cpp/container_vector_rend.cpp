/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_rend.exe ./cpp/container_vector_rend.cpp && (cd ../_build/cpp/;./container_vector_rend.exe)
https://en.cppreference.com/w/cpp/container/vector/rend
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
int main()
{
    std::vector<int> nums {1, 2, 4, 8, 16};
    std::vector<std::string> fruits {"orange", "apple", "raspberry"};
    std::vector<char> empty;
    // Print vector.
    std::for_each(nums.rbegin(), nums.rend(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';
    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.rbegin() << '\n';
    if (empty.rbegin() == empty.rend())
        std::cout << "vector 'empty' is indeed empty.\n";
}

