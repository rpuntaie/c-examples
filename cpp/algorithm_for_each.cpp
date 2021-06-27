/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_for_each.exe ./cpp/algorithm_for_each.cpp && (cd ../_build/cpp/;./algorithm_for_each.exe)
https://en.cppreference.com/w/cpp/algorithm/for_each
*/
#include <vector>
#include <algorithm>
#include <iostream>
struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};
int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    auto print = [](const int& n) { std::cout << " " << n; };
    std::cout << "before:";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });
    // calls Sum::operator() for each number
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());
    std::cout << "after: ";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}

