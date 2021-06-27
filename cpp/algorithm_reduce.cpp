/*
g++ --std=c++20 -pthread -ltbb -o ../_build/cpp/algorithm_reduce.exe ./cpp/algorithm_reduce.cpp && (cd ../_build/cpp/;./algorithm_reduce.exe)
https://en.cppreference.com/w/cpp/algorithm/reduce
*/
#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
int main()
{
    auto eval = [](auto fun) {
        const auto t1 = std::chrono::high_resolution_clock::now();
        const auto [name, result] = fun();
        const auto t2 = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << std::setprecision(1) << name << " result "
                  << result << " took " << ms.count() << " ms\n";
    };
    {
        const std::vector<double> v(100'000'007, 0.1);
        eval([&v]{ return std::pair{"std::accumulate (double)",
            std::accumulate(v.cbegin(), v.cend(), 0.0)}; } );
        eval([&v]{ return std::pair{"std::reduce (seq, double)",
            std::reduce(std::execution::seq, v.cbegin(), v.cend())}; } );
        eval([&v]{ return std::pair{"std::reduce (par, double)",
            std::reduce(std::execution::par, v.cbegin(), v.cend())}; } );
    }{
        const std::vector<long> v(100'000'007, 1);
        eval([&v]{ return std::pair{"std::accumulate (long)",
            std::accumulate(v.cbegin(), v.cend(), 0)}; } );
        eval([&v]{ return std::pair{"std::reduce (seq, long)",
            std::reduce(std::execution::seq, v.cbegin(), v.cend())}; } );
        eval([&v]{ return std::pair{"std::reduce (par, long)",
            std::reduce(std::execution::par, v.cbegin(), v.cend())}; } );
    }
}

