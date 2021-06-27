/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_normal_distribution.exe ./cpp/numeric_random_normal_distribution.cpp && (cd ../_build/cpp/;./numeric_random_normal_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
int main()
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{5,2};
    std::map<int, int> hist{};
    for(int n=0; n<10000; ++n) {
        ++hist[std::round(d(gen))];
    }
    for(auto p : hist) {
        std::cout << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

