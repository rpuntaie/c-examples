/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_forward_list_begin.exe ./cpp/container_forward_list_begin.cpp && (cd ../_build/cpp/;./container_forward_list_begin.exe)
https://en.cppreference.com/w/cpp/container/forward_list/begin
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <forward_list>
int main()
{
    std::forward_list<int> nums {1, 2, 4, 8, 16};
    std::forward_list<std::string> fruits {"orange", "apple", "raspberry"};
    std::forward_list<char> empty;
    // Print forward_list.
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
    // Sums all integers in the forward_list nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
    // Prints the first fruit in the forward_list fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
    if (empty.begin() == empty.end())
        std::cout << "forward_list 'empty' is indeed empty.\n";
}

