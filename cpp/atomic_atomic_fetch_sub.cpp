/*
g++ --std=c++20 -pthread -o ../_build/cpp/atomic_atomic_fetch_sub.exe ./cpp/atomic_atomic_fetch_sub.cpp && (cd ../_build/cpp/;./atomic_atomic_fetch_sub.exe)
https://en.cppreference.com/w/cpp/atomic/atomic_fetch_sub
*/
#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <numeric>
const int N = 50;
std::atomic<int> cnt;
std::vector<int> data(N);
void reader(int id) 
{
    for (;;) {
        int idx = atomic_fetch_sub_explicit(&cnt, 1, std::memory_order_relaxed);
        if (idx >= 0) {
            std::cout << "reader " << std::to_string(id) << " processed item "
                      << std::to_string(data[idx]) << '\n';
        } else {
            std::cout << "reader " << std::to_string(id) << " done\n";
            break;
        }
    }
}
int main()
{
    std::iota(data.begin(), data.end(), 1);
    cnt = data.size() - 1;
    std::vector<std::thread> v;
    for (int n = 0; n < 5; ++n) {
        v.emplace_back(reader, n);
    }
    for (auto& t : v) {
        t.join();
    }
}

