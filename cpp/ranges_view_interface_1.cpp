/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_view_interface_1.exe ./cpp/ranges_view_interface_1.cpp && (cd ../_build/cpp/;./ranges_view_interface_1.exe)
https://en.cppreference.com/w/cpp/ranges/view_interface
*/
#include <ranges>
#include <vector>
#include <iostream>
template <class T, class A>
class VectorView : public std::ranges::view_interface<VectorView<T, A>> {
public:
    // We need to define a default constructor to satisfy the view concept.
    VectorView() = default;
    VectorView(const std::vector<T, A>& vec) :
        m_begin(vec.cbegin()), m_end(vec.cend()) {}
    auto begin() const { return m_begin; }
    auto end() const { return m_end; }
private:
    typename std::vector<T, A>::const_iterator m_begin, m_end;
};
int main()
{
    std::vector<int> v = {1, 4, 9, 16};
    VectorView view_over_v{v};
    // We can iterate with begin() and end().
    for (int n : view_over_v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    // We get operator[] for free when inherting from view_interface
    // since we satisfy the random_access_range concept.
    for (std::ptrdiff_t i = 0; i < view_over_v.size(); i++) {
        std::cout << "v[" << i << "] = " << view_over_v[i] << '\n';
    }
}

