/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_not1.exe ./cpp/utility_functional_not1.cpp && (cd ../_build/cpp/;./utility_functional_not1.exe)
https://en.cppreference.com/w/cpp/utility/functional/not1
*/
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <iostream>
#include <vector>
struct LessThan7 : std::unary_function<int, bool>
{
    bool operator()(int i) const { return i < 7; }
};
int main()
{
    std::vector<int> v(10);
    std::iota(begin(v), end(v), 0);
    std::cout << std::count_if(begin(v), end(v), std::not1(LessThan7())) << "\n";
    //same as above, but using `std::function`
    std::function<bool(int)> less_than_9 = [](int x){ return x < 9; };
    std::cout << std::count_if(begin(v), end(v), std::not1(less_than_9)) << "\n";
}

