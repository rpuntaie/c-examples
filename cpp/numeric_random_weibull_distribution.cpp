/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_weibull_distribution.exe ./cpp/numeric_random_weibull_distribution.cpp && (cd ../_build/cpp/;./numeric_random_weibull_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/weibull_distribution
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::weibull_distribution<> d;
    std::map<int, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[std::round(d(gen))];
    }
    for(auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

