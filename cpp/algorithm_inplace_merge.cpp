/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_inplace_merge.exe ./cpp/algorithm_inplace_merge.cpp && (cd ../_build/cpp/;./algorithm_inplace_merge.exe)
https://en.cppreference.com/w/cpp/algorithm/inplace_merge
*/
#include <vector>
#include <iostream>
#include <algorithm>
template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}
int main()
{
    std::vector<int> v{8, 2, -2, 0, 11, 11, 1, 7, 3};
    merge_sort(v.begin(), v.end());
    for(auto n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

