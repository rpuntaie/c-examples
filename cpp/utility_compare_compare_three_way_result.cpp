/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_compare_compare_three_way_result.exe ./cpp/utility_compare_compare_three_way_result.cpp && (cd ../_build/cpp/;./utility_compare_compare_three_way_result.exe)
https://en.cppreference.com/w/cpp/utility/compare/compare_three_way_result
*/
#include <compare>
#include <type_traits>
#include <iostream>
template <class Ord>
void print_cmp_type()
{
    if constexpr (std::is_same_v<Ord, std::strong_ordering>)
        std::cout << "strong ordering\n";
    else if constexpr (std::is_same_v<Ord, std::weak_ordering>)
        std::cout << "weak ordering\n";
    else if constexpr (std::is_same_v<Ord, std::partial_ordering>)
        std::cout << "partial ordering\n";
    else
        std::cout << "illegal comparison result type\n";
}
int main()
{
    print_cmp_type<std::compare_three_way_result_t<int>>();
    print_cmp_type<std::compare_three_way_result_t<double>>();
}

