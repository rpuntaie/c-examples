/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_sample.exe ./cpp/algorithm_sample.cpp && (cd ../_build/cpp/;./algorithm_sample.exe)
https://en.cppreference.com/w/cpp/algorithm/sample
*/
#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
int main()
{
    std::string in = "hgfedcba", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';
}

