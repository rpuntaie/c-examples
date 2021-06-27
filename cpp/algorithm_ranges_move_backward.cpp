/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_move_backward.exe ./cpp/algorithm_ranges_move_backward.cpp && (cd ../_build/cpp/;./algorithm_ranges_move_backward.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/move_backward
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std::literals;
using Vec = std::vector<std::string>;
void print(std::string_view rem, Vec const& vec) {
    std::cout << rem << "[" << vec.size() << "]: ";
    for (const std::string& s : vec)
        std::cout << (s.size() ? s : "·"s) << ' ';
    std::cout << '\n';
}
int main()
{
    Vec a{"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};
    Vec b(a.size());
    print("Before move:\n" "a", a);
    print("b", b);
    std::ranges::move_backward(a, b.end());
    print("\n" "Move a >> b:\n" "a", a);
    print("b", b);
    std::ranges::move_backward(b.begin(), b.end(), a.end());
    print("\n" "Move b >> a:\n" "a", a);
    print("b", b);
    std::ranges::move_backward(a.begin(), a.begin()+3, a.end());
    print("\n" "Overlapping move a[0, 3) >> a[5, 8):\n" "a", a);
}

