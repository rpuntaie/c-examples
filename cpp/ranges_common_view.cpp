/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_common_view.exe ./cpp/ranges_common_view.cpp && (cd ../_build/cpp/;./ranges_common_view.exe)
https://en.cppreference.com/w/cpp/ranges/common_view
*/
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
void print_sum(auto&& v) {
    auto cv { v | std::views::common };  // turns into a "common-range"
    using T = decltype(*cv.begin());  // needed to get initial value of the sum
    for (bool first{true}; auto const& e : cv)  // print range
        std::cout << (first ? first = false, "" : " + ") << e;
    std::cout << " = " << std::accumulate(cv.begin(), cv.end(), T{}) << '\n';
}
int main() {
    const auto v1 = {1, 2, 3, 4, 5};
    print_sum(v1);
    auto take3 = v1 | std::views::reverse | std::views::take(3);
    print_sum(take3); // 5 + 4 + 3
    using namespace std::literals;
    const auto v2 = { "[alpha]"s, "[beta]"s, "[gamma]"s };
    print_sum(v2);
}

