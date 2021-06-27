/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_count.exe ./cpp/algorithm_count.cpp && (cd ../_build/cpp/;./algorithm_count.exe)
https://en.cppreference.com/w/cpp/algorithm/count
*/
#include <algorithm>
#include <iostream>
#include <array>
int main()
{
    constexpr std::array v = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    // determine how many integers match a target value.
    int target1 = 3;
    int target2 = 5;
    int num_items1 = std::count(v.begin(), v.end(), target1);
    int num_items2 = std::count(v.begin(), v.end(), target2);
    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';
    // use a lambda expression to count elements divisible by 3.
    int num_items3 = std::count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});
    std::cout << "number divisible by three: " << num_items3 << '\n';
    // A simplified version of `distance` with O(N) complexity:
    auto distance = [](auto first, auto last) {
        return std::count_if(first, last, [](auto){return true;});
    };
    static_assert(distance(v.begin(), v.end()) == 10);
}

