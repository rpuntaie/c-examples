/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_lcm.exe ./cpp/numeric_lcm.cpp && (cd ../_build/cpp/;./numeric_lcm.exe)
https://en.cppreference.com/w/cpp/numeric/lcm
*/
#include <numeric>
int main() {
    constexpr int p {2 * 2 * 3};
    constexpr int q {2 * 3 * 3};
    static_assert(2 * 2 * 3 * 3 == std::lcm(p, q));
}

