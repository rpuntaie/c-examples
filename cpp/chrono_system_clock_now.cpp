/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_system_clock_now.exe ./cpp/chrono_system_clock_now.cpp && (cd ../_build/cpp/;./chrono_system_clock_now.exe)
https://en.cppreference.com/w/cpp/chrono/system_clock/now
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <chrono>
volatile int sink;
int main()
{
    std::cout << std::fixed << std::setprecision(9) << std::left;
    for (auto size = 1ull; size < 1000'000'000ull; size *= 100) {
        // record start time
        auto start = std::chrono::system_clock::now();
        // do some work
        std::vector<int> v(size, 42);
        sink = std::accumulate(v.begin(), v.end(), 0u); // make sure it's a side effect
        // record end time
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "Time to fill and iterate a vector of " << std::setw(9)
                  << size << " ints : " << diff.count() << " s\n";
    }
}

