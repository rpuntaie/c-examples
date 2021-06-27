/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_identity.exe ./cpp/utility_functional_identity.cpp && (cd ../_build/cpp/;./utility_functional_identity.exe)
https://en.cppreference.com/w/cpp/utility/functional/identity
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>
struct Pair {
    int n; std::string s;
    friend std::ostream& operator<< (std::ostream& os, const Pair& p) {
        return os << "{ " << p.n << ", " << p.s << " }";
    }
};
// A range-printer that can print projected (modified) elements of a range.
template <std::ranges::input_range R,
          typename Projection = std::identity> //<- Notice the default projection
void print(std::string_view const rem, R&& r, Projection proj = {}) {
    std::cout << rem << "{ ";
    std::ranges::for_each(r, [](const auto& o){ std::cout << o << ' '; }, proj);
    std::cout << "}\n";
}
int main()
{
    const std::vector<Pair> v{ {1, "one"}, {2, "two"}, {3, "three"} };
    print("Print using std::identity as a projection: ", v);
    print("Project the Pair::n: ", v, &Pair::n);
    print("Project the Pair::s: ", v, &Pair::s);
    print("Print using custom closure as a projection: ", v,
        [](Pair const& p) { return std::to_string(p.n) + ':' + p.s; });
}

