/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_copy_backward.exe ./cpp/algorithm_ranges_copy_backward.cpp && (cd ../_build/cpp/;./algorithm_ranges_copy_backward.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/copy_backward
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>
void print(std::string_view rem, std::ranges::forward_range auto const& r) {
    std::cout << rem << ": ";
    for (auto const& elem : r) { std::cout << elem << ' '; }
    std::cout << '\n';
}
int main()
{
    const auto src = {1, 2, 3, 4};
    print("src", src);
    std::vector<int> dst (src.size() + 2);
    std::ranges::copy_backward(src, dst.end());
    print("dst", dst);
    std::ranges::fill(dst, 0);
    const auto [in, out] =
        std::ranges::copy_backward(src.begin(), src.end() - 2, dst.end());
    print("dst", dst);
    std::cout
        << "(in - src.begin) == " << std::distance(src.begin(), in) << '\n'
        << "(out - dst.begin) == " << std::distance(dst.begin(), out) << '\n';
}

