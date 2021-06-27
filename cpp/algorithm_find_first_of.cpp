/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_find_first_of.exe ./cpp/algorithm_find_first_of.cpp && (cd ../_build/cpp/;./algorithm_find_first_of.exe)
https://en.cppreference.com/w/cpp/algorithm/find_first_of
*/
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v{0, 2, 3, 25, 5};
    const auto t = {3, 19, 10, 2};
    auto result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());
    if (result == v.end()) {
        std::cout << "no elements of v were equal to 3, 19, 10 or 2\n";
    } else {
        std::cout << "found a match at "
                  << std::distance(v.begin(), result) << "\n";
    }
 }

