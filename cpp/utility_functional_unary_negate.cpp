/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_unary_negate.exe ./cpp/utility_functional_unary_negate.cpp && (cd ../_build/cpp/;./utility_functional_unary_negate.exe)
https://en.cppreference.com/w/cpp/utility/functional/unary_negate
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
struct less_than_7 : std::unary_function<int, bool>
{
    bool operator()(int i) const { return i < 7; }
};
int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    std::unary_negate<less_than_7> not_less_than_7((less_than_7()));
    std::cout << std::count_if(v.begin(), v.end(), not_less_than_7);
    /* C++11 solution:
        // Use std::function<bool (int)>
        std::function<bool (int)> not_less_than_7 =
            [](int x)->bool{ return !less_than_7()(x); };
        std::cout << std::count_if(v.begin(), v.end(), not_less_than_7);
    */
}

