/*
g++ --std=c++20 -pthread -ltbb -o ../_build/cpp/algorithm_transform_reduce.exe ./cpp/algorithm_transform_reduce.cpp && (cd ../_build/cpp/;./algorithm_transform_reduce.exe)
https://en.cppreference.com/w/cpp/algorithm/transform_reduce
*/
#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <execution>
int main()
{
    std::vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);
    double result = std::transform_reduce(
        std::execution::par,
        xvalues.begin(), xvalues.end(),
        yvalues.begin(), 0.0
    );
    std::cout << result << '\n';
}

