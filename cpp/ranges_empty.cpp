/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_empty.exe ./cpp/ranges_empty.cpp && (cd ../_build/cpp/;./ranges_empty.exe)
https://en.cppreference.com/w/cpp/ranges/empty
*/
#include <iostream>
#include <ranges>
#include <vector>
template <std::ranges::input_range R>
void print(R&& r)
{
    if (std::ranges::empty(r)) {
        std::cout << "\tEmpty\n";
        return;
    }
    std::cout << "\tElements:";
    for (const auto& element : r) {
        std::cout << ' ' << element;
    }
    std::cout << '\n';
}
int main()
{
    {
        auto v = std::vector<int>{1, 2, 3};
        std::cout << "1. calling ranges::empty on std::vector:\n";
        print(v);
        v.clear();
        print(v);
    }
    {
        std::cout << "2. calling ranges::empty on std::initializer_list:\n";
        auto il = {7, 8, 9};
        print(il);
        print(std::initializer_list<int>{});
    }
    {
        std::cout << "2. calling ranges::empty on a raw array:\n";
        int array[] = {4, 5, 6}; // array has a known bound
        print(array);
    }
    {
        struct NoEmptyNorSize : private std::vector<int> {
            auto begin() { return std::vector<int>::begin(); }
            auto end() { return std::vector<int>::end(); }
        };
        std::cout << "3. calling ranges::empty on an object that satisfies only case 3):\n";
        print(NoEmptyNorSize{});
    }
}

