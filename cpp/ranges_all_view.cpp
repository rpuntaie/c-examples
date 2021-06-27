/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_all_view.exe ./cpp/ranges_all_view.cpp && (cd ../_build/cpp/;./ranges_all_view.exe)
https://en.cppreference.com/w/cpp/ranges/all_view
*/
#include <ranges>
#include <vector>
#include <iostream>
#include <type_traits>
int main()
{
    std::vector<int> v{0,1,2,3,4,5};
    for(int n : std::views::all(v) | std::views::take(2) ) {
        std::cout << n << ' ';
    }
    static_assert(std::is_same<
        decltype(std::views::single(42)),
        std::ranges::single_view<int>
        >{});
    static_assert(std::is_same<
        decltype(std::views::all(v)),
        std::ranges::ref_view<std::vector<int, std::allocator<int>>>
        >{});
    int a[]{1,2,3,4};
    static_assert(std::is_same<
        decltype(std::views::all(a)),
        std::ranges::ref_view<int [4]>
        >{});
    static_assert(std::is_same<
        decltype(std::ranges::subrange{std::begin(a)+1, std::end(a)-1}),
        std::ranges::subrange<int*, int*, std::ranges::subrange_kind(1)>
        >{});
}

