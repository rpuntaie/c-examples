/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_merge.exe ./cpp/algorithm_ranges_merge.cpp && (cd ../_build/cpp/;./algorithm_ranges_merge.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/merge
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
void print(const auto& in1, const auto& in2, auto first, auto last) {
    std::cout << "{ ";
    for (const auto& e : in1) { std::cout << e << ' '; }
    std::cout << "} +\n{ ";
    for (const auto& e : in2) { std::cout << e << ' '; }
    std::cout << "} =\n{ ";
    while (!(first == last)) { std::cout << *first++ << ' '; }
    std::cout << "}\n\n";
}
int main()
{
    std::vector<int> in1, in2, out;
    in1 = {1, 2, 3, 4, 5};
    in2 = {      3, 4, 5, 6, 7};
    out.resize(in1.size() + in2.size());
    const auto ret = std::ranges::merge(in1, in2, out.begin());
    print(in1, in2, out.begin(), ret.out);
    in1 = {1, 2, 3, 4, 5, 5, 5};
    in2 = {      3, 4, 5, 6, 7};
    out.clear();
    out.reserve(in1.size() + in2.size());
    std::ranges::merge(in1, in2, std::back_inserter(out));
    print(in1, in2, out.cbegin(), out.cend());
}

