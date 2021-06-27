/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_mismatch.exe ./cpp/algorithm_mismatch.cpp && (cd ../_build/cpp/;./algorithm_mismatch.exe)
https://en.cppreference.com/w/cpp/algorithm/mismatch
*/
#include <iostream>
#include <string>
#include <algorithm>
std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(),
                       std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}
int main()
{
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}

