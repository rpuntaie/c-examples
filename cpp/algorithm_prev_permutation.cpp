/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_prev_permutation.exe ./cpp/algorithm_prev_permutation.cpp && (cd ../_build/cpp/;./algorithm_prev_permutation.exe)
https://en.cppreference.com/w/cpp/algorithm/prev_permutation
*/
#include <algorithm>
#include <string>
#include <iostream>
#include <functional>
int main()
{
    std::string s="abc";
    std::sort(s.begin(), s.end(), std::greater<char>());
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << '\n';
}

