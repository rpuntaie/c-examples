/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_geometric_distribution.exe ./cpp/numeric_random_geometric_distribution.cpp && (cd ../_build/cpp/;./numeric_random_geometric_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/geometric_distribution
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::geometric_distribution<> d; // same as std::negative_binomial_distribution<> d(1, 0.5);
    std::map<int, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[d(gen)];
    }
    for(auto p : hist) {
        std::cout << p.first <<
                ' ' << std::string(p.second/100, '*') << '\n';
    }
}

