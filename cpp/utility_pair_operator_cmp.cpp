/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_pair_operator_cmp.exe ./cpp/utility_pair_operator_cmp.cpp && (cd ../_build/cpp/;./utility_pair_operator_cmp.exe)
https://en.cppreference.com/w/cpp/utility/pair/operator_cmp
*/
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
int main()
{
    std::vector<std::pair<int, std::string>> v = { {2, "baz"},
                                                   {2, "bar"},
                                                   {1, "foo"} };
    std::sort(v.begin(), v.end());
    for(auto p: v) {
        std::cout << "{" << p.first << ", " << std::quoted(p.second) << "}\n";
    }
}

