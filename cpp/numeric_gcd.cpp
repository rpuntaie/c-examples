/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_gcd.exe ./cpp/numeric_gcd.cpp && (cd ../_build/cpp/;./numeric_gcd.exe)
https://en.cppreference.com/w/cpp/numeric/gcd
*/
#include <numeric>
int main() {
    constexpr int p {2 * 2 * 3};
    constexpr int q {2 * 3 * 3};
    static_assert(2 * 3 == std::gcd(p, q));
}

