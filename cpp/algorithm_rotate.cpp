/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_rotate.exe ./cpp/algorithm_rotate.cpp && (cd ../_build/cpp/;./algorithm_rotate.exe)
https://en.cppreference.com/w/cpp/algorithm/rotate
*/
#include <vector>
#include <iostream>
#include <algorithm>
auto print = [](auto const& remark, auto const& v) {
    std::cout << remark;
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
};
int main()
{
    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
    print("before sort:\t\t", v);
    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
    }
    print("after sort:\t\t", v);
    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 1, v.end());
    print("simple rotate left:\t", v);
    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    print("simple rotate right:\t", v);
}

