/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_unique_copy.exe ./cpp/algorithm_unique_copy.cpp && (cd ../_build/cpp/;./algorithm_unique_copy.exe)
https://en.cppreference.com/w/cpp/algorithm/unique_copy
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
int main()
{
    std::string s1 = "The      string    with many       spaces!";
    std::cout << "before: " << s1 << '\n';
    std::string s2;
    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                     [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });
    std::cout << "after:  " << s2 << '\n';
}

