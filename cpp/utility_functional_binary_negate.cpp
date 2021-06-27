/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_binary_negate.exe ./cpp/utility_functional_binary_negate.cpp && (cd ../_build/cpp/;./utility_functional_binary_negate.exe)
https://en.cppreference.com/w/cpp/utility/functional/binary_negate
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
struct same : std::binary_function<int, int, bool>
{
    bool operator()(int a, int b) const { return a == b; }
};
int main()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 0; i < 10; ++i) v1.push_back(i);
    for (int i = 0; i < 10; ++i) v2.push_back(10 - i);
    std::vector<bool> v3(v1.size());
    std::binary_negate<same> not_same((same()));
    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), not_same);
    /* C++11 solution:
        // Use std::function<bool (int, int)>
        std::function<bool (int, int)> not_same =
            [](int x, int y)->bool{ return !same()(x, y); };
        std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), not_same);
    */
    std::cout.setf(std::ios_base::boolalpha);
    for (int i = 0; i < 10; ++i)
        std::cout << v1[i] << ' ' << v2[i] << ' ' << v3[i] << '\n';
}

