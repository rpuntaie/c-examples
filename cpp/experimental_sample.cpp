/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_sample.exe ./cpp/experimental_sample.cpp && (cd ../_build/cpp/;./experimental_sample.exe)
https://en.cppreference.com/w/cpp/experimental/sample
*/
#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <experimental/algorithm>
int main()
{
    std::string in = "abcdefgh", out;
    std::experimental::sample(in.begin(), in.end(), std::back_inserter(out),
                              5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';
}

